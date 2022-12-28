-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with Interfaces,
     Interfaces.C.Strings,
     Ada.Characters.Handling;

use Interfaces,
    Interfaces.C.Strings,
    Ada.Characters.Handling;

with OBC_MODEL_DATAVIEW;
use OBC_MODEL_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with System_Dataview;
use System_Dataview;
with adaasn1rtl;
use adaasn1rtl;
with State_Handler_Entrypoint_Datamodel; use State_Handler_Entrypoint_Datamodel;

with State_Handler_Entrypoint_RI;
package State_Handler_Entrypoint with Elaborate_Body is
   ctxt : aliased asn1SccState_handler_entrypoint_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (State_Handler_Entrypoint_RI.To_C_Pointer (asn1SccState_Handler_Entrypoint_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "state_handler_entrypoint_state";
   procedure Startup with Export, Convention => C, Link_Name => "State_Handler_Entrypoint_startup";
   --  Provided interface "poll_aoi"
   procedure poll_aoi;
   pragma Export(C, poll_aoi, "state_handler_entrypoint_PI_poll_aoi");
   --  Provided interface "poll_mcp"
   procedure poll_mcp;
   pragma Export(C, poll_mcp, "state_handler_entrypoint_PI_poll_mcp");
   --  Provided interface "toggle_pwr"
   procedure toggle_pwr;
   pragma Export(C, toggle_pwr, "state_handler_entrypoint_PI_toggle_pwr");
   --  Provided interface "trig_aoi"
   procedure trig_aoi;
   pragma Export(C, trig_aoi, "state_handler_entrypoint_PI_trig_aoi");
   --  Provided interface "trig_mcp"
   procedure trig_mcp;
   pragma Export(C, trig_mcp, "state_handler_entrypoint_PI_trig_mcp");
   --  Provided interface "trig_pwr"
   procedure trig_pwr;
   pragma Export(C, trig_pwr, "state_handler_entrypoint_PI_trig_pwr");
   --  Required interface "send_tm_aoi"
   procedure RI_0_send_tm_aoi (lfp : in out asn1SccLocation_Fix_Packet) renames State_Handler_Entrypoint_RI.send_tm_aoi;
   --  Required interface "send_tm_mcp"
   procedure RI_0_send_tm_mcp (mcp : in out asn1SccMode_Change_Packet) renames State_Handler_Entrypoint_RI.send_tm_mcp;
   --  Synchronous Required Interface "collect_tm"
   procedure RI_0_collect_tm renames State_Handler_Entrypoint_RI.collect_tm;
   --  Synchronous Required Interface "request_loc"
   procedure RI_0_request_loc (Lfp : out asn1SccLocation_Fix_Packet) renames State_Handler_Entrypoint_RI.request_loc;
   --  Synchronous Required Interface "request_tc"
   procedure RI_0_request_tc (Mcp : out asn1SccMode_Change_Packet) renames State_Handler_Entrypoint_RI.request_tc;
   --  Synchronous Required Interface "validate_mc_vs_tm"
   procedure RI_0_validate_mc_vs_tm renames State_Handler_Entrypoint_RI.validate_mc_vs_tm;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 7;
end State_Handler_Entrypoint;