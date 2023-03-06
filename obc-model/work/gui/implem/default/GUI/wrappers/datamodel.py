#!/usr/bin/python

import DV

FVname = "gui"

tc = {}
tm = {}
errCodes = {}

tm["send_tm_aoi"] = {'nodeTypename': 'Location-Fix-Packet', 'type': 'SEQUENCE', 'id': 'send_tm_aoi', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'INTEGER', 'id': 't', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': 0, 'maxR': 4294967294},
{'nodeTypename': '', 'type': 'REAL', 'id': 'lat', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -90.00000000000000000000, 'maxR': 90.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'lon', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -180.00000000000000000000, 'maxR': 180.00000000000000000000}]}
tm["send_tm_mcp"] = {'nodeTypename': 'Mode-Change-Packet', 'type': 'SEQUENCE', 'id': 'send_tm_mcp', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'INTEGER', 'id': 'target_addr', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': 0, 'maxR': 6},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'target_mode', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': 0, 'maxR': 4},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'ttl_ms', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': 0, 'maxR': 10000}]}
tc["trig_aoi"] = {'nodeTypename': 'T-Null-Record', 'type': 'SEQUENCE', 'id': 'trig_aoi', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[]}
tc["trig_mcp"] = {'nodeTypename': 'T-Null-Record', 'type': 'SEQUENCE', 'id': 'trig_mcp', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[]}
tc["trig_pwr"] = {'nodeTypename': 'T-Null-Record', 'type': 'SEQUENCE', 'id': 'trig_pwr', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[]}
