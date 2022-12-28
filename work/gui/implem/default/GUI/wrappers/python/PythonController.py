from __future__ import absolute_import


import threading, time, sys, os, ctypes

import DV
try:
    PythonAccess = ctypes.cdll.LoadLibrary("./PythonAccess.so")
except OSError:
    folder = os.path.dirname(os.path.abspath(__file__))
    PythonAccess = ctypes.cdll.LoadLibrary(folder + "/PythonAccess.so")
    sys.path.append(folder)
OpenMsgQueueForReading = PythonAccess.OpenMsgQueueForReading
OpenMsgQueueForReading.restype = ctypes.c_int
CloseMsgQueue =  PythonAccess.CloseMsgQueue
GetMsgQueueBufferSize = PythonAccess.GetMsgQueueBufferSize
GetMsgQueueBufferSize.restype = ctypes.c_int
RetrieveMessageFromQueue = PythonAccess.RetrieveMessageFromQueue
RetrieveMessageFromQueue.restype = ctypes.c_int
import dataview_uniq_asn
i_send_tm_aoi = ctypes.c_int.in_dll(PythonAccess, "ii_send_tm_aoi").value
i_send_tm_mcp = ctypes.c_int.in_dll(PythonAccess, "ii_send_tm_mcp").value
i_trig_aoi = ctypes.c_int.in_dll(PythonAccess, "ii_trig_aoi").value
SendTC_trig_aoi = PythonAccess.SendTC_trig_aoi
i_trig_mcp = ctypes.c_int.in_dll(PythonAccess, "ii_trig_mcp").value
SendTC_trig_mcp = PythonAccess.SendTC_trig_mcp
i_trig_pwr = ctypes.c_int.in_dll(PythonAccess, "ii_trig_pwr").value
SendTC_trig_pwr = PythonAccess.SendTC_trig_pwr

class Poll_gui(threading.Thread):
    def run(self):
        self._bDie = False
        while True:
            if self._bDie:
                return
            queue_name = str(os.geteuid()) + "_gui_PI_Python_queue"
            self._msgQueue = OpenMsgQueueForReading(queue_name.encode("utf-8"))
            if (self._msgQueue != -1): break
            print("Communication channel over %d_gui_PI_Python_queue not established yet...\n" % os.geteuid())
            time.sleep(1)
        bufferSize = GetMsgQueueBufferSize(self._msgQueue)
        self._pMem = ctypes.create_string_buffer(bufferSize).raw
        while not self._bDie:
            self.messageReceivedType = RetrieveMessageFromQueue(self._msgQueue, bufferSize, self._pMem)
            if self.messageReceivedType == -1:
                time.sleep(0.01)
                continue
            ProcessTM(self)

def Invoke_trig_aoi(var_T_Null_Record):
    if -1 == SendTC_trig_aoi(var_T_Null_Record._ptr):
        print('Failed to send TC: trig_aoi...\n')
        raise IOError("trig_aoi")

def Invoke_trig_mcp(var_T_Null_Record):
    if -1 == SendTC_trig_mcp(var_T_Null_Record._ptr):
        print('Failed to send TC: trig_mcp...\n')
        raise IOError("trig_mcp")

def Invoke_trig_pwr(var_T_Null_Record):
    if -1 == SendTC_trig_pwr(var_T_Null_Record._ptr):
        print('Failed to send TC: trig_pwr...\n')
        raise IOError("trig_pwr")

def ProcessTM(self):
    if self.messageReceivedType == i_send_tm_aoi:
        print("\n"+chr(27)+"[32m" + "Received Telemetry: send_tm_aoi" + chr(27) + "[0m\n")
        backup = self._pMem
        # Read the data for param lfp
        var_lfp = dataview_uniq_asn.Location_Fix_Packet()
        var_lfp.SetData(self._pMem)
        print("Parameter lfp:")
        var_lfp.PrintAll()
        print()
        # self._pMem = DV.MovePtrBySizeOf_Location_Fix_Packet(self._pMem)
        # Revert the pointer to start of the data
        self._pMem = backup
    if self.messageReceivedType == i_send_tm_mcp:
        print("\n"+chr(27)+"[32m" + "Received Telemetry: send_tm_mcp" + chr(27) + "[0m\n")
        backup = self._pMem
        # Read the data for param mcp
        var_mcp = dataview_uniq_asn.Mode_Change_Packet()
        var_mcp.SetData(self._pMem)
        print("Parameter mcp:")
        var_mcp.PrintAll()
        print()
        # self._pMem = DV.MovePtrBySizeOf_Mode_Change_Packet(self._pMem)
        # Revert the pointer to start of the data
        self._pMem = backup

if __name__ == "__main__":
    poll_gui = Poll_gui()
    poll_gui.start()
    try:
        time.sleep(1e8)
    except:
        poll_gui._bDie = True
        poll_gui.join()