# (C) Semantix Information Technologies, Neuropublic, and European Space Agency
#
# Licensed under the GPL with Runtime Exception.
# Note that there are no charges (royalties) for the generated code.
from __future__ import absolute_import

import os
import re
import copy
import sys
import DV_Types  # pylint: disable=import-error
from ctypes import (
    cdll, c_void_p, c_ubyte, c_double, c_uint,
    c_longlong, c_bool, c_int, c_long, c_char, c_ulonglong
)

if sys.version_info > (3,):
    long = int

# load the *getset.so in this folder
script_path = os.path.dirname(os.path.realpath(__file__))
soFileNames = [
    filename
    for filename in os.listdir(script_path)
    if filename.endswith("_getset.so")
]
if len(soFileNames) != 1:
    raise Exception("Failed to locate a single _getset.so under " + script_path)

JMP = cdll.LoadLibrary(os.path.join(script_path, soFileNames[0]))

# BitStream constructor
CreateStream = JMP.CreateStream
CreateStream.restype = c_void_p
# BitStream destructor
DestroyStream = JMP.DestroyStream
# BitStream reset
ResetStream = JMP.ResetStream
# Get number of bytes in encoded stream
GetStreamCurrentLength = JMP.GetStreamCurrentLength
GetStreamCurrentLength.restype = c_uint

# Access BitStream buffer
GetBitstreamBuffer = JMP.GetBitstreamBuffer
GetBitstreamBuffer.restype = c_void_p
# Read from buffer
GetBufferByte = JMP.GetBufferByte
GetBufferByte.restype = c_ubyte
# Write to buffer
SetBufferByte = JMP.SetBufferByte

# Create pErr space for Encoders - i.e. sizeof(int)
CreateInstanceOf_int = JMP.CreateInstanceOf_int
CreateInstanceOf_int.restype = c_void_p
# Release pErr space for Encoders
DestroyInstanceOf_int = JMP.DestroyInstanceOf_int


class AsnCoderError(Exception):
    pass


def CleanNameAsPythonWants(name):
    """ASN.1 ids have minuses... turn non-ID chars to '_'"""
    return re.sub(r'[^a-zA-Z0-9_]', '_', name)
Clean = CleanNameAsPythonWants


def myassert(b):
    """assert that shows the call stack when it fails"""
    if not b:
        raise AsnCoderError("Assertion failed...")


class DataStream(object):
    """ASN1SCC BitStream equivalent"""
    def __init__(self, bufferSize):
        """bufferSize: use the DV.TYPENAME_REQUIRED_BYTES_FOR_ENCODING"""
        myassert(isinstance(bufferSize, int))
        self._bs = c_void_p(CreateStream(bufferSize))
        self._bufferSize = bufferSize

    def __del__(self):
        """Releases the encoded data and the bitstream structure pointing to them"""
        DestroyStream(self._bs)

    def Reset(self):
        """Rewinds the currentByte and currentBit to the start"""
        ResetStream(self._bs)

    def GetPyString(self):
        # print "Reading",
        if sys.version_info > (3,):
            msg = b""
            pData = c_void_p(GetBitstreamBuffer(self._bs))
            for i in range(0, GetStreamCurrentLength(self._bs)):
                b = GetBufferByte(pData, i)
                msg += bytes([b])
                # print b, ",",
        else:
            msg = ""
            pData = c_void_p(GetBitstreamBuffer(self._bs))
            for i in range(0, GetStreamCurrentLength(self._bs)):
                b = GetBufferByte(pData, i)
                msg += chr(b)
                # print b, ",",
        # print "EOF"
        return msg

    def SetFromPyString(self, data):
        strLength = len(data)
        assert self._bufferSize >= strLength
        self._bs.count = strLength
        pData = c_void_p(GetBitstreamBuffer(self._bs))
        # print "Writing",
        if sys.version_info > (3,):
            for i in range(0, strLength):
                b = data[i]
                # print b, ",",
                SetBufferByte(pData, i, b)
        else:
            for i in range(0, strLength):
                b = ord(data[i])
                # print b, ",",
                SetBufferByte(pData, i, b)
        # print "EOF"


class COMMON(object):
    """This class is used to implement ALL the Python "proxy" classes for
ASN1SCC types.

It uses the __getattr__ call to hook into all the accesses that Python
considers "unexpected". Therefore, when the script does this...

    a = T_SEQUENCE()
    print a.x.Get()
    a.x.Set(12)

... __getattr__ is called to ask us how to provide a ".x" member.
We do two things to cope:

(1) we form the equivalent path to the C getter/setter function
    (in self._Caccessor)
(2) we form a list of params, which is basically the indexes of
    whatever arrays we meet in the access path

So if the script does...

    a.x.y[0].z.k[2].w.Get()

then the params list carries [0,2], to pass it as an argument to the
C getter when it is called (in response to the "Get" method call).

Some key points:
    When the chain ends (in a .Get, .Set, .GetLength or .SetLength
call), we have to reset the "paths" we have formed, so that the
next chain will restart from the beginning. That's what the Reset
method does.
However, we also have some helper functions for OCTET STRINGs:
GetPyString and SetFromPyString. These have to do a per-byte loop,
and if they used the "Get" and "Set" as they originally were,
the path would be reset after accessing the [0] element...
So we added a keyword boolean param called "reset", which disables
this Reset when it is used from within GetPyString and
SetFromPyString.
    Another keyword param is postfix: it is simply used to allow
re-use of the Get and Set code for the GetLength and SetLength
members of SEQUENCEOF/SETOFs and OCTETSTRINGs:

An example for SetLength:

  T_SEQUENCE ::= SEQUENCE { y SEQUENCE (SIZE(4)) OF INTEGER }

    a = T_SEQUENCE()
    a.y.SetLength(4)
    a.y[0].Set(1)
    a.y[1].Set(4)
    a.y[2].Set(9)
    a.y[3].Set(16)
"""

    allowed = ["_nodeTypeName", "_ptr", "_pErr", "_Caccessor", "_accessPath",
               "_params", "_new_ptr"]
# , "Get", "GetLength", "Set", "SetLength", "Reset", "Encode", "Decode", "SetFromPyString", "GetPyString", "allowed"]

    def __init__(self, nodeTypeName, ptr=None):
        myassert(isinstance(nodeTypeName, str))
        self._nodeTypeName = nodeTypeName
        self._new_ptr = ptr is None
        constructor = getattr(JMP, "CreateInstanceOf_" + Clean(nodeTypeName))
        constructor.restype = c_void_p
        self._ptr = ptr or constructor()
        self._ptr = c_void_p(self._ptr)
        self._pErr = c_void_p(CreateInstanceOf_int())
        self._Caccessor = ""
        self._params = []
        self._accessPath = ""

    def Reset(self, state=None):
        if state is None:
            self._Caccessor = ""
            self._params = []
            self._accessPath = ""
        else:
            self._Caccessor, self._params, self._accessPath = state[0][:], copy.deepcopy(state[1]), state[2][:]

    def GetState(self):
        return self._Caccessor[:], copy.deepcopy(self._params), self._accessPath[:]

    def SetData(self, src):
        bridgeFct = getattr(JMP, "SetDataFor_" + Clean(self._nodeTypeName))
        bridgeFct(self._ptr, src)

    def __del__(self):
        ''' Destructor: free memory only if it was allocated at creation '''
        DestroyInstanceOf_int(self._pErr)
        if self._new_ptr:
            destructor = getattr(JMP, "DestroyInstanceOf_" + Clean(self._nodeTypeName))
            destructor(self._ptr)

    def __str__(self):
        return "Choose the information you want - whole-structure or sequence dump not supported."

    def __getattr__(self, x):
        self._Caccessor += "_" + Clean(x)
        self._accessPath += "." + x
        return self

    def __setattr__(self, name, value):
        if name not in COMMON.allowed:
            self.Reset()
            raise AsnCoderError("You can only use .Set(XYZ) and .SetLength(XYZ) to assign values, don't use '='")
        object.__setattr__(self, name, value)

    def __getitem__(self, idx):
        self._Caccessor += "_iDx"
        self._params.append(idx)
        self._accessPath += "[" + str(idx) + "]"
        return self

    def Get(self, **args):  # postfix="", reset=True
        try:
            bridgeFuncName = Clean(self._nodeTypeName) + "_" + self._Caccessor + "_Get" + args.get("postfix", "")
            if bridgeFuncName not in DV_Types.funcTypeLookup:
                raise AsnCoderError("Function %s not found in lookup - contact support." % bridgeFuncName)
            resType = DV_Types.funcTypeLookup[bridgeFuncName]
            if resType.endswith('*'):
                cTypesResultType = c_void_p
            else:
                cTypesResultType = {
                    'asn1SccSint': c_longlong,
                    'asn1SccUint': c_ulonglong,
                    'byte': c_ubyte,
                    'double': c_double,
                    'flag': c_bool,
                    'int': c_int,
                    'long': c_long,
                    'char': c_ubyte # char
                }.get(resType, None)
                if cTypesResultType is None:
                    raise AsnCoderError("Result type of %s not yet supported in the Python mapper - contact support." % resType)
            bridgeFunc = getattr(JMP, bridgeFuncName)
            bridgeFunc.restype = cTypesResultType
            retVal = bridgeFunc(self._ptr, *self._params)
        except Exception as e:
            oldAP = self._accessPath
            if args.get("reset", True):
                self.Reset()
            raise AsnCoderError("The access path you used (%s) is not valid. (%s)" % (oldAP, str(e)))
        if args.get("reset", True):
            self.Reset()
        return retVal

    def Set(self, value, **args):  # postfix="", reset=True
        try:
            # print Clean(self._nodeTypeName) + "_" + self._Caccessor + "_Set"+postfix
            bridgeFunc = getattr(JMP, Clean(self._nodeTypeName) + "_" + self._Caccessor + "_Set" + args.get("postfix", ""))
            if isinstance(value, float):
                ctypesValue = c_double(value)
            elif isinstance(value, (int, long)):
                ctypesValue = c_longlong(value)
            else:
                ctypesValue = value
            self._params.append(ctypesValue)
            bridgeFunc(self._ptr, *self._params)
            self._params.pop()
        except Exception as e:
            oldAP = self._accessPath
            if args.get("reset", True):
                self.Reset()
            raise AsnCoderError(
                "The access path you used (%s) or the value you tried to assign (%s) is not valid. %s" % (
                    oldAP, str(value), str(e)))
        if args.get("reset", True):
            self.Reset()

    def GetLength(self, reset=True):
        return self.Get(postfix="Length", reset=reset)

    def SetLength(self, value, reset=True):
        self.Set(value, postfix="Length", reset=reset)

    @staticmethod
    def getErrCode(pErr):
        errCode = 0
        for i in range(4):
            errCode = (errCode << 8) | GetBufferByte(pErr, (3 - i))
        return errCode

    def Encode(self, bitstream, bACN=False):
        """Returns (booleanSuccess, ASN1SCC iErrorCode)
grep for the errorcode value inside ASN1SCC generated headers."""
        myassert(isinstance(bitstream, DataStream))
        bitstream.Reset()
        suffix = "_ACN_Encode" if bACN else "_Encode"
        EncodeFuncName = Clean(self._nodeTypeName) + suffix
        EncodeFunc = getattr(JMP, EncodeFuncName)
        success = EncodeFunc(self._ptr, bitstream._bs, self._pErr, True)
        if not success:
            raise AsnCoderError("Error in %s, code: %d" % (EncodeFuncName,
                                                           COMMON.getErrCode(self._pErr)))

    def Decode(self, bitstream, bACN=False):
        """Returns (booleanSuccess, ASN1SCC iErrorCode)
grep for the errorcode value inside ASN1SCC generated headers."""
        myassert(isinstance(bitstream, DataStream))
        suffix = "_ACN_Decode" if bACN else "_Decode"
        DecodeFuncName = Clean(self._nodeTypeName) + suffix
        DecodeFunc = getattr(JMP, DecodeFuncName)
        success = DecodeFunc(self._ptr, bitstream._bs, self._pErr)
        if not success:
            raise AsnCoderError("Error in %s, code: %d" % (DecodeFuncName,
                                                           COMMON.getErrCode(self._pErr)))

    def EncodeACN(self, bitstream):
        self.Encode(bitstream, True)

    def DecodeACN(self, bitstream):
        self.Decode(bitstream, True)

    def Initialise(self):
        initialiseFunc = getattr(JMP, Clean(self._nodeTypeName) + "_Initialize")
        initialiseFunc(self._ptr)

    def IsConstraintValid(self):
        # Allocate temp space to store error code (avoid race condition that _pErr would cause)
        pErr = c_void_p(CreateInstanceOf_int())
        validatorFunc = getattr(JMP, Clean(self._nodeTypeName) + "_IsConstraintValid")
        isValid = validatorFunc(self._ptr, pErr)
        errorCode = COMMON.getErrCode(pErr)
        DestroyInstanceOf_int(pErr)
        return isValid, errorCode

# Type-specific helpers...

# OCTET STRING

    def SetFromPyString(self, src):
        # This function is shared between IA5String and OCTET STRING
        # therefore the caller may be sending a string or bytes
        strLength = len(src)
        self.SetLength(strLength, False)
        self._Caccessor += "_iDx"
        accessPath = self._accessPath
        if sys.version_info > (3,):
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                try:
                    # if src is a string
                    self.Set(ord(src[idx]), reset=False)
                except:
                    # If src is a set of bytes
                    self.Set(src[idx], reset=False)
                self._params.pop()
        else:
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                self.Set(ord(src[idx]), reset=False)
                self._params.pop()
        self.Reset()

    def GetPyString(self, tryToDecodeAscii=True):
        ''' Return an OCTET STRING as bytes ; by default try to decode
        the bytes as a printable ASCII string to keep backward compatibility.
        Applications should set this flag to False and use the GetAsciiString
        function (see below) to get the value of IA5Strings.
        '''
        if sys.version_info > (3,):
            retval = b""
            strLength = self.GetLength(False)
            self._Caccessor += "_iDx"
            accessPath = self._accessPath
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                retval += bytes([self.Get(reset=False)])
                self._params.pop()
            self.Reset()
            if tryToDecodeAscii:
                try:
                    return retval.decode("utf-8")
                except:
                    pass
            return retval
        else:
            retval = ""
            strLength = self.GetLength(False)
            self._Caccessor += "_iDx"
            accessPath = self._accessPath
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                retval += chr(self.Get(reset=False))
                self._params.pop()
            self.Reset()
            return retval

    def GetAsciiString(self):
        ''' Return IA5String '''
        if sys.version_info > (3,):
            retval = b""
            strLength = self.GetLength(False)
            self._Caccessor += "_iDx"
            accessPath = self._accessPath
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                retval += bytes([self.Get(reset=False)])
                self._params.pop()
            self.Reset()
            return retval.decode("utf-8")
        else:
            retval = ""
            strLength = self.GetLength(False)
            self._Caccessor += "_iDx"
            accessPath = self._accessPath
            for idx in range(0, strLength):
                self._params.append(idx)
                self._accessPath = accessPath + "[" + str(idx) + "]"
                retval += chr(self.Get(reset=False))
                self._params.pop()
            self.Reset()
            return retval
