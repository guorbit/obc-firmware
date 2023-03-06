pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
pragma Warnings (Off, "redundant with clause in body");

pragma Warnings (Off, "no entities of ""OBC_MODEL_DATAVIEW"" are referenced");
pragma Warnings (Off, "use clause for package ""OBC_MODEL_DATAVIEW"" has no effect");
pragma Warnings (Off, "unit ""OBC_MODEL_DATAVIEW"" is not referenced");
with OBC_MODEL_DATAVIEW;
pragma Warnings (On, "no entities of ""OBC_MODEL_DATAVIEW"" are referenced");
pragma Warnings (On, "use clause for package ""OBC_MODEL_DATAVIEW"" has no effect");
pragma Warnings (On, "unit ""OBC_MODEL_DATAVIEW"" is not referenced");

pragma Warnings (On, "redundant with clause in body");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through previous use_type_clause at");
use type OBC_MODEL_DATAVIEW.asn1SccCounterK;
use type OBC_MODEL_DATAVIEW.asn1SccMode_Change_Packet_ttl_ms;
use type OBC_MODEL_DATAVIEW.asn1SccMode_Change_Packet;
use type OBC_MODEL_DATAVIEW.asn1SccSubsystem_Address;
use type OBC_MODEL_DATAVIEW.asn1SccSystem_Mode;
use type OBC_MODEL_DATAVIEW.asn1SccLocation_Fix_Packet;
use type OBC_MODEL_DATAVIEW.asn1SccTime_UNIX;
use type OBC_MODEL_DATAVIEW.asn1SccLatitude_WGS84;
use type OBC_MODEL_DATAVIEW.asn1SccLongitude_WGS84;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through previous use_type_clause at");
package body State_handler_entrypoint_Datamodel with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccState_handler_entrypoint_States_Equal (val1, val2 :  asn1SccState_handler_entrypoint_States) return Boolean
is

begin
	return val1 = val2;

end asn1SccState_handler_entrypoint_States_Equal;

function asn1SccState_handler_entrypoint_States_IsConstraintValid(val : asn1SccState_handler_entrypoint_States) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret.Success := (((val = asn1Sccwait)) OR ((val = asn1Sccsleep)));
    ret.ErrorCode := (if ret.Success then 0 else ERR_STATE_HANDLER_ENTRYPOINT_STATES);
    return ret;
end asn1SccState_handler_entrypoint_States_IsConstraintValid;





function asn1SccState_handler_entrypoint_Context_Equal (val1, val2 :  asn1SccState_handler_entrypoint_Context) return Boolean
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ""ret"" has no effect");

begin
    ret := (val1.state = val2.state);

    if ret then
        ret := (val1.init_done = val2.init_done);

        if ret then
            ret := (val1.k = val2.k);

            if ret then
                ret := (val1.s = val2.s);

                if ret then
                    ret := (val1.w = val2.w);

                    if ret then
                        ret := (val1.k_max = val2.k_max);

                        if ret then
                            ret := (val1.s_max = val2.s_max);

                            if ret then
                                ret := (val1.w_max = val2.w_max);

                                if ret then
                                    ret := OBC_MODEL_DATAVIEW.asn1SccMode_Change_Packet_Equal(val1.mcp, val2.mcp);

                                    if ret then
                                        ret := OBC_MODEL_DATAVIEW.asn1SccLocation_Fix_Packet_Equal(val1.lfp, val2.lfp);

                                    end if;
                                end if;
                            end if;
                        end if;
                    end if;
                end if;
            end if;
        end if;
    end if;
	return ret;

end asn1SccState_handler_entrypoint_Context_Equal;

function asn1SccState_handler_entrypoint_Context_IsConstraintValid(val : asn1SccState_handler_entrypoint_Context) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ""ret"" has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ""ret"" has no effect");        
begin
    ret := asn1SccState_handler_entrypoint_States_IsConstraintValid(val.state);
    if ret.Success then
        ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.k);
        if ret.Success then
            ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.s);
            if ret.Success then
                ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.w);
                if ret.Success then
                    ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.k_max);
                    if ret.Success then
                        ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.s_max);
                        if ret.Success then
                            ret := OBC_MODEL_DATAVIEW.asn1SccCounterK_IsConstraintValid(val.w_max);
                            if ret.Success then
                                ret := OBC_MODEL_DATAVIEW.asn1SccMode_Change_Packet_IsConstraintValid(val.mcp);
                                if ret.Success then
                                    ret := OBC_MODEL_DATAVIEW.asn1SccLocation_Fix_Packet_IsConstraintValid(val.lfp);
                                end if;
                            end if;
                        end if;
                    end if;
                end if;
            end if;
        end if;
    end if;
    return ret;
end asn1SccState_handler_entrypoint_Context_IsConstraintValid;




pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end State_handler_entrypoint_Datamodel;