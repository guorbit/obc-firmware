pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
pragma Warnings (Off, "redundant with clause in body");
pragma Warnings (On, "redundant with clause in body");

package body OBC_MODEL_DATAVIEW with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccCounterK_Equal (val1, val2 :  asn1SccCounterK) return Boolean
is

begin
	return val1 = val2;

end asn1SccCounterK_Equal;

function asn1SccCounterK_IsConstraintValid(val : asn1SccCounterK) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (val <= 1000);
    ret.ErrorCode := (if ret.Success then 0 else ERR_COUNTERK);
    return ret;
end asn1SccCounterK_IsConstraintValid;





function asn1SccTime_UNIX_Equal (val1, val2 :  asn1SccTime_UNIX) return Boolean
is

begin
	return val1 = val2;

end asn1SccTime_UNIX_Equal;

function asn1SccTime_UNIX_IsConstraintValid(val : asn1SccTime_UNIX) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (val <= 4294967294);
    ret.ErrorCode := (if ret.Success then 0 else ERR_TIME_UNIX);
    return ret;
end asn1SccTime_UNIX_IsConstraintValid;





function asn1SccLatitude_WGS84_Equal (val1, val2 :  asn1SccLatitude_WGS84) return Boolean
is

begin
	return adaasn1rtl.Asn1Real_Equal(val1, val2);

end asn1SccLatitude_WGS84_Equal;

function asn1SccLatitude_WGS84_IsConstraintValid(val : asn1SccLatitude_WGS84) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := ((-9.0000000000000000000E+001 <= val) AND (val <= 9.0000000000000000000E+001));
    ret.ErrorCode := (if ret.Success then 0 else ERR_LATITUDE_WGS84);
    return ret;
end asn1SccLatitude_WGS84_IsConstraintValid;





function asn1SccLongitude_WGS84_Equal (val1, val2 :  asn1SccLongitude_WGS84) return Boolean
is

begin
	return adaasn1rtl.Asn1Real_Equal(val1, val2);

end asn1SccLongitude_WGS84_Equal;

function asn1SccLongitude_WGS84_IsConstraintValid(val : asn1SccLongitude_WGS84) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := ((-1.8000000000000000000E+002 <= val) AND (val <= 1.8000000000000000000E+002));
    ret.ErrorCode := (if ret.Success then 0 else ERR_LONGITUDE_WGS84);
    return ret;
end asn1SccLongitude_WGS84_IsConstraintValid;





function asn1SccLocation_Equal (val1, val2 :  asn1SccLocation) return Boolean
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ""ret"" has no effect");

begin
    ret := (adaasn1rtl.Asn1Real_Equal(val1.lat, val2.lat));

    if ret then
        ret := (adaasn1rtl.Asn1Real_Equal(val1.lon, val2.lon));

    end if;
	return ret;

end asn1SccLocation_Equal;

function asn1SccLocation_IsConstraintValid(val : asn1SccLocation) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret := asn1SccLatitude_WGS84_IsConstraintValid(val.lat);
    if ret.Success then
        ret := asn1SccLongitude_WGS84_IsConstraintValid(val.lon);
    end if;
    return ret;
end asn1SccLocation_IsConstraintValid;





function asn1SccLocation_Fix_Packet_Equal (val1, val2 :  asn1SccLocation_Fix_Packet) return Boolean
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ""ret"" has no effect");

begin
    ret := (val1.t = val2.t);

    if ret then
        ret := (adaasn1rtl.Asn1Real_Equal(val1.lat, val2.lat));

        if ret then
            ret := (adaasn1rtl.Asn1Real_Equal(val1.lon, val2.lon));

        end if;
    end if;
	return ret;

end asn1SccLocation_Fix_Packet_Equal;

function asn1SccLocation_Fix_Packet_IsConstraintValid(val : asn1SccLocation_Fix_Packet) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret := asn1SccTime_UNIX_IsConstraintValid(val.t);
    if ret.Success then
        ret := asn1SccLatitude_WGS84_IsConstraintValid(val.lat);
        if ret.Success then
            ret := asn1SccLongitude_WGS84_IsConstraintValid(val.lon);
        end if;
    end if;
    return ret;
end asn1SccLocation_Fix_Packet_IsConstraintValid;





function asn1SccTemperature_Generic_Equal (val1, val2 :  asn1SccTemperature_Generic) return Boolean
is

begin
	return adaasn1rtl.Asn1Real_Equal(val1, val2);

end asn1SccTemperature_Generic_Equal;

function asn1SccTemperature_Generic_IsConstraintValid(val : asn1SccTemperature_Generic) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := ((-2.0000000000000000000E+002 <= val) AND (val <= 2.0000000000000000000E+002));
    ret.ErrorCode := (if ret.Success then 0 else ERR_TEMPERATURE_GENERIC);
    return ret;
end asn1SccTemperature_Generic_IsConstraintValid;





function asn1SccDeployment_Digital_Equal (val1, val2 :  asn1SccDeployment_Digital) return Boolean
is

begin
	return val1 = val2;

end asn1SccDeployment_Digital_Equal;

function asn1SccDeployment_Digital_IsConstraintValid(val : asn1SccDeployment_Digital) return adaasn1rtl.ASN1_RESULT
is
    pragma Unreferenced (val);
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    return ret;
end asn1SccDeployment_Digital_IsConstraintValid;





function asn1SccDeployment_Analogue_Equal (val1, val2 :  asn1SccDeployment_Analogue) return Boolean
is

begin
	return adaasn1rtl.Asn1Real_Equal(val1, val2);

end asn1SccDeployment_Analogue_Equal;

function asn1SccDeployment_Analogue_IsConstraintValid(val : asn1SccDeployment_Analogue) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := ((0.0000000000000000000E+000 <= val) AND (val <= 1.0000000000000000000E+002));
    ret.ErrorCode := (if ret.Success then 0 else ERR_DEPLOYMENT_ANALOGUE);
    return ret;
end asn1SccDeployment_Analogue_IsConstraintValid;





function asn1SccSystem_Mode_Equal (val1, val2 :  asn1SccSystem_Mode) return Boolean
is

begin
	return val1 = val2;

end asn1SccSystem_Mode_Equal;

function asn1SccSystem_Mode_IsConstraintValid(val : asn1SccSystem_Mode) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (val <= 4);
    ret.ErrorCode := (if ret.Success then 0 else ERR_SYSTEM_MODE);
    return ret;
end asn1SccSystem_Mode_IsConstraintValid;





function asn1SccSubsystem_Address_Equal (val1, val2 :  asn1SccSubsystem_Address) return Boolean
is

begin
	return val1 = val2;

end asn1SccSubsystem_Address_Equal;

function asn1SccSubsystem_Address_IsConstraintValid(val : asn1SccSubsystem_Address) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (val <= 6);
    ret.ErrorCode := (if ret.Success then 0 else ERR_SUBSYSTEM_ADDRESS);
    return ret;
end asn1SccSubsystem_Address_IsConstraintValid;





function asn1SccMode_Change_Packet_ttl_ms_Equal (val1, val2 :  asn1SccMode_Change_Packet_ttl_ms) return Boolean
is

begin
	return val1 = val2;

end asn1SccMode_Change_Packet_ttl_ms_Equal;

function asn1SccMode_Change_Packet_Equal (val1, val2 :  asn1SccMode_Change_Packet) return Boolean
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ""ret"" has no effect");

begin
    ret := (val1.target_addr = val2.target_addr);

    if ret then
        ret := (val1.target_mode = val2.target_mode);

        if ret then
            ret := asn1SccMode_Change_Packet_ttl_ms_Equal(val1.ttl_ms, val2.ttl_ms);

        end if;
    end if;
	return ret;

end asn1SccMode_Change_Packet_Equal;

function asn1SccMode_Change_Packet_ttl_ms_IsConstraintValid(val : asn1SccMode_Change_Packet_ttl_ms) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (val <= 10000);
    ret.ErrorCode := (if ret.Success then 0 else ERR_MODE_CHANGE_PACKET_TTL_MS);
    return ret;
end asn1SccMode_Change_Packet_ttl_ms_IsConstraintValid;

function asn1SccMode_Change_Packet_IsConstraintValid(val : asn1SccMode_Change_Packet) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret := asn1SccSubsystem_Address_IsConstraintValid(val.target_addr);
    if ret.Success then
        ret := asn1SccSystem_Mode_IsConstraintValid(val.target_mode);
        if ret.Success then
            ret := asn1SccMode_Change_Packet_ttl_ms_IsConstraintValid(val.ttl_ms);
        end if;
    end if;
    return ret;
end asn1SccMode_Change_Packet_IsConstraintValid;





pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end OBC_MODEL_DATAVIEW;