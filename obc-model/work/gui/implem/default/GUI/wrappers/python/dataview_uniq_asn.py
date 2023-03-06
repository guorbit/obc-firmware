from functools import partial

import DV

from Stubs import (
    myassert, Clean, DataStream, COMMON)

class CounterK(COMMON):
    def __init__(self, ptr=None):
        super(CounterK, self).__init__("CounterK", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Time_UNIX(COMMON):
    def __init__(self, ptr=None):
        super(Time_UNIX, self).__init__("Time_UNIX", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Latitude_WGS84(COMMON):
    def __init__(self, ptr=None):
        super(Latitude_WGS84, self).__init__("Latitude_WGS84", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Longitude_WGS84(COMMON):
    def __init__(self, ptr=None):
        super(Longitude_WGS84, self).__init__("Longitude_WGS84", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Location(COMMON):
    # Ordered list of fields:
    children_ordered = ['lat', 'lon']

    def __init__(self, ptr=None):
        super(Location, self).__init__("Location", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("lat ")
        lines.append(" "+str(self.lat.Get()))
        lines.append(', ')
        lines.append("lon ")
        lines.append(" "+str(self.lon.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Location_Fix_Packet(COMMON):
    # Ordered list of fields:
    children_ordered = ['t', 'lat', 'lon']

    def __init__(self, ptr=None):
        super(Location_Fix_Packet, self).__init__("Location_Fix_Packet", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("t ")
        lines.append(" "+str(self.t.Get()))
        lines.append(', ')
        lines.append("lat ")
        lines.append(" "+str(self.lat.Get()))
        lines.append(', ')
        lines.append("lon ")
        lines.append(" "+str(self.lon.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Temperature_Generic(COMMON):
    def __init__(self, ptr=None):
        super(Temperature_Generic, self).__init__("Temperature_Generic", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Deployment_Digital(COMMON):
    def __init__(self, ptr=None):
        super(Deployment_Digital, self).__init__("Deployment_Digital", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()!=0).upper())

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Deployment_Analogue(COMMON):
    def __init__(self, ptr=None):
        super(Deployment_Analogue, self).__init__("Deployment_Analogue", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class System_Mode(COMMON):
    def __init__(self, ptr=None):
        super(System_Mode, self).__init__("System_Mode", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Subsystem_Address(COMMON):
    def __init__(self, ptr=None):
        super(Subsystem_Address, self).__init__("Subsystem_Address", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Mode_Change_Packet(COMMON):
    # Ordered list of fields:
    children_ordered = ['target-addr', 'target-mode', 'ttl-ms']

    def __init__(self, ptr=None):
        super(Mode_Change_Packet, self).__init__("Mode_Change_Packet", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("target-addr ")
        lines.append(" "+str(self.target_addr.Get()))
        lines.append(', ')
        lines.append("target-mode ")
        lines.append(" "+str(self.target_mode.Get()))
        lines.append(', ')
        lines.append("ttl-ms ")
        lines.append(" "+str(self.ttl_ms.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Int32(COMMON):
    def __init__(self, ptr=None):
        super(T_Int32, self).__init__("T_Int32", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt32(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt32, self).__init__("T_UInt32", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Int8(COMMON):
    def __init__(self, ptr=None):
        super(T_Int8, self).__init__("T_Int8", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt8(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt8, self).__init__("T_UInt8", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Boolean(COMMON):
    def __init__(self, ptr=None):
        super(T_Boolean, self).__init__("T_Boolean", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()!=0).upper())

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Null_Record(COMMON):
    # Ordered list of fields:
    children_ordered = ['']

    def __init__(self, ptr=None):
        super(T_Null_Record, self).__init__("T_Null_Record", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PID(COMMON):
    # Allowed enumerants:
    gui = 0
    loc_provider = 1
    state_handler_entrypoint = 2
    tc_provider = 3
    tc_validation = 4
    tm_collection = 5
    tm_provider = 6
    env = 7
    allowed = [gui, loc_provider, state_handler_entrypoint, tc_provider, tc_validation, tm_collection, tm_provider, env]
    def __init__(self, ptr=None):
        super(PID, self).__init__("PID", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+{'0': 'gui', '1': 'loc-provider', '2': 'state-handler-entrypoint', '3': 'tc-provider', '4': 'tc-validation', '5': 'tm-collection', '6': 'tm-provider', '7': 'env'}[str(self.Get())])

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


