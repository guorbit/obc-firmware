pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
with adaasn1rtl;


pragma Warnings (Off, "unit ""System"" is not referenced");
with System;
pragma Warnings (On, "unit ""System"" is not referenced");

pragma Warnings (Off, "use clause for package ""adaasn1rtl"" has no effect");
use adaasn1rtl;
pragma Warnings (On, "use clause for package ""adaasn1rtl"" has no effect");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through package use clause at line");
use type adaasn1rtl.OctetBuffer;
use type adaasn1rtl.BitArray;
use type adaasn1rtl.Asn1UInt;
use type adaasn1rtl.Asn1Int;
use type adaasn1rtl.BIT;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through package use clause at line");



package OBC_MODEL_DATAVIEW with SPARK_Mode
is


subtype asn1SccCounterK is adaasn1rtl.Asn1UInt range 0 .. 1000;


function asn1SccCounterK_Equal(val1, val2 : asn1SccCounterK) return Boolean;

ERR_COUNTERK:constant Integer := 1; -- (0 .. 1000)
function asn1SccCounterK_IsConstraintValid(val : asn1SccCounterK) return adaasn1rtl.ASN1_RESULT;

function asn1SccCounterK_Init return asn1SccCounterK;
subtype asn1SccTime_UNIX is adaasn1rtl.Asn1UInt range 0 .. 4294967294;


function asn1SccTime_UNIX_Equal(val1, val2 : asn1SccTime_UNIX) return Boolean;

ERR_TIME_UNIX:constant Integer := 6; -- (0 .. 4294967294)
function asn1SccTime_UNIX_IsConstraintValid(val : asn1SccTime_UNIX) return adaasn1rtl.ASN1_RESULT;

function asn1SccTime_UNIX_Init return asn1SccTime_UNIX;
subtype asn1SccLatitude_WGS84 is adaasn1rtl.Asn1Real;


function asn1SccLatitude_WGS84_Equal(val1, val2 : asn1SccLatitude_WGS84) return Boolean;

ERR_LATITUDE_WGS84:constant Integer := 11; -- (-90.0 .. 90.0)
function asn1SccLatitude_WGS84_IsConstraintValid(val : asn1SccLatitude_WGS84) return adaasn1rtl.ASN1_RESULT;

function asn1SccLatitude_WGS84_Init return asn1SccLatitude_WGS84;
subtype asn1SccLongitude_WGS84 is adaasn1rtl.Asn1Real;


function asn1SccLongitude_WGS84_Equal(val1, val2 : asn1SccLongitude_WGS84) return Boolean;

ERR_LONGITUDE_WGS84:constant Integer := 16; -- (-180.0 .. 180.0)
function asn1SccLongitude_WGS84_IsConstraintValid(val : asn1SccLongitude_WGS84) return adaasn1rtl.ASN1_RESULT;

function asn1SccLongitude_WGS84_Init return asn1SccLongitude_WGS84;
-- asn1SccLocation --------------------------------------------

type asn1SccLocation is record 
    lat : asn1SccLatitude_WGS84;
    lon : asn1SccLongitude_WGS84;
end record;


function asn1SccLocation_Equal(val1, val2 : asn1SccLocation) return Boolean;

ERR_LOCATION:constant Integer := 41; -- 
ERR_LOCATION_LAT_2:constant Integer := 26; -- 
ERR_LOCATION_LON_2:constant Integer := 36; -- 
function asn1SccLocation_IsConstraintValid(val : asn1SccLocation) return adaasn1rtl.ASN1_RESULT;

function asn1SccLocation_Init return asn1SccLocation;
-- asn1SccLocation_Fix_Packet --------------------------------------------

type asn1SccLocation_Fix_Packet is record 
    t : asn1SccTime_UNIX;
    lat : asn1SccLatitude_WGS84;
    lon : asn1SccLongitude_WGS84;
end record;


function asn1SccLocation_Fix_Packet_Equal(val1, val2 : asn1SccLocation_Fix_Packet) return Boolean;

ERR_LOCATION_FIX_PACKET:constant Integer := 131; -- 
ERR_LOCATION_FIX_PACKET_T_2:constant Integer := 106; -- 
ERR_LOCATION_FIX_PACKET_LAT_2:constant Integer := 116; -- 
ERR_LOCATION_FIX_PACKET_LON_2:constant Integer := 126; -- 
function asn1SccLocation_Fix_Packet_IsConstraintValid(val : asn1SccLocation_Fix_Packet) return adaasn1rtl.ASN1_RESULT;

function asn1SccLocation_Fix_Packet_Init return asn1SccLocation_Fix_Packet;
subtype asn1SccTemperature_Generic is adaasn1rtl.Asn1Real;


function asn1SccTemperature_Generic_Equal(val1, val2 : asn1SccTemperature_Generic) return Boolean;

ERR_TEMPERATURE_GENERIC:constant Integer := 46; -- (-200.0 .. 200.0)
function asn1SccTemperature_Generic_IsConstraintValid(val : asn1SccTemperature_Generic) return adaasn1rtl.ASN1_RESULT;

function asn1SccTemperature_Generic_Init return asn1SccTemperature_Generic;
subtype asn1SccDeployment_Digital is adaasn1rtl.Asn1Boolean;


function asn1SccDeployment_Digital_Equal(val1, val2 : asn1SccDeployment_Digital) return Boolean;

ERR_DEPLOYMENT_DIGITAL:constant Integer := 51; -- 
function asn1SccDeployment_Digital_IsConstraintValid(val : asn1SccDeployment_Digital) return adaasn1rtl.ASN1_RESULT;

function asn1SccDeployment_Digital_Init return asn1SccDeployment_Digital;
subtype asn1SccDeployment_Analogue is adaasn1rtl.Asn1Real;


function asn1SccDeployment_Analogue_Equal(val1, val2 : asn1SccDeployment_Analogue) return Boolean;

ERR_DEPLOYMENT_ANALOGUE:constant Integer := 56; -- (0.0 .. 100.0)
function asn1SccDeployment_Analogue_IsConstraintValid(val : asn1SccDeployment_Analogue) return adaasn1rtl.ASN1_RESULT;

function asn1SccDeployment_Analogue_Init return asn1SccDeployment_Analogue;
subtype asn1SccSystem_Mode_index_range is Integer range 0..4;
type asn1SccSystem_Mode is (asn1Sccidle, asn1Sccuplink, asn1Sccdownlink, asn1Sccimaging, asn1Sccprocessing) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccSystem_Mode use
    (asn1Sccidle => 0, asn1Sccuplink => 1, asn1Sccdownlink => 2, asn1Sccimaging => 3, asn1Sccprocessing => 4);

function asn1SccSystem_Mode_Equal(val1, val2 : asn1SccSystem_Mode) return Boolean;

ERR_SYSTEM_MODE:constant Integer := 61; -- idle | uplink | downlink | imaging | processing
function asn1SccSystem_Mode_IsConstraintValid(val : asn1SccSystem_Mode) return adaasn1rtl.ASN1_RESULT;

function asn1SccSystem_Mode_Init return asn1SccSystem_Mode;
subtype asn1SccSubsystem_Address_index_range is Integer range 0..6;
type asn1SccSubsystem_Address is (asn1Sccobc, asn1Scccomms, asn1Sccelectrical, asn1Sccmechanical, asn1Scccontrol, asn1Sccsoftware, asn1Sccpayload) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccSubsystem_Address use
    (asn1Sccobc => 0, asn1Scccomms => 1, asn1Sccelectrical => 2, asn1Sccmechanical => 3, asn1Scccontrol => 4, asn1Sccsoftware => 5, asn1Sccpayload => 6);

function asn1SccSubsystem_Address_Equal(val1, val2 : asn1SccSubsystem_Address) return Boolean;

ERR_SUBSYSTEM_ADDRESS:constant Integer := 66; -- obc | comms | electrical | mechanical | control | software | payload
function asn1SccSubsystem_Address_IsConstraintValid(val : asn1SccSubsystem_Address) return adaasn1rtl.ASN1_RESULT;

function asn1SccSubsystem_Address_Init return asn1SccSubsystem_Address;
-- asn1SccMode_Change_Packet --------------------------------------------
subtype asn1SccMode_Change_Packet_ttl_ms is adaasn1rtl.Asn1UInt range 0 .. 10000;


type asn1SccMode_Change_Packet is record 
    target_addr : asn1SccSubsystem_Address;
    target_mode : asn1SccSystem_Mode;
    ttl_ms : asn1SccMode_Change_Packet_ttl_ms;
end record;


function asn1SccMode_Change_Packet_ttl_ms_Equal(val1, val2 : asn1SccMode_Change_Packet_ttl_ms) return Boolean;

function asn1SccMode_Change_Packet_Equal(val1, val2 : asn1SccMode_Change_Packet) return Boolean;

ERR_MODE_CHANGE_PACKET_TTL_MS:constant Integer := 91; -- (0 .. 10000)
function asn1SccMode_Change_Packet_ttl_ms_IsConstraintValid(val : asn1SccMode_Change_Packet_ttl_ms) return adaasn1rtl.ASN1_RESULT;

ERR_MODE_CHANGE_PACKET:constant Integer := 96; -- 
ERR_MODE_CHANGE_PACKET_TARGET_ADDR_2:constant Integer := 76; -- 
ERR_MODE_CHANGE_PACKET_TARGET_MODE_2:constant Integer := 86; -- 
function asn1SccMode_Change_Packet_IsConstraintValid(val : asn1SccMode_Change_Packet) return adaasn1rtl.ASN1_RESULT;

function asn1SccMode_Change_Packet_ttl_ms_Init return asn1SccMode_Change_Packet_ttl_ms;
function asn1SccMode_Change_Packet_Init return asn1SccMode_Change_Packet;
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide OBC_MODEL_DATAVIEW;


end OBC_MODEL_DATAVIEW;