--  This file is a stub for the implementation of the required interfaces
--  It is normally overwritten by TASTE with the actual connection to the
--  middleware. If you use Opengeode independently from TASTE you must
--  edit the .adb (body) with your own implementation of these functions.
--  The body stub will be generated only once.

with OBC_MODEL_DATAVIEW;
use OBC_MODEL_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with System_Dataview;
use System_Dataview;
with adaasn1rtl;
use adaasn1rtl;

with Interfaces.C.Strings; use Interfaces.C.Strings;

package State_Handler_Entrypoint_RI is

   --  In TASTE, used to return the state as char * (but uses malloc so
   --  just return null here - feel free to implement it differently)
   function To_C_Pointer (State_As_String : String) return Chars_Ptr is
      (Null_Ptr);


procedure send_tm_aoi (lfp : in out asn1SccLocation_Fix_Packet);
procedure send_tm_mcp (mcp : in out asn1SccMode_Change_Packet);
procedure collect_tm;
procedure request_loc (Lfp : out asn1SccLocation_Fix_Packet);
procedure request_tc (Mcp : out asn1SccMode_Change_Packet);
procedure validate_mc_vs_tm;
end State_Handler_Entrypoint_RI;