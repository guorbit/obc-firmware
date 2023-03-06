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
with Payload_Subsystem_Datamodel; use Payload_Subsystem_Datamodel;

with Payload_Subsystem_RI;
package Payload_Subsystem with Elaborate_Body is
   ctxt : aliased asn1SccPayload_subsystem_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (Payload_Subsystem_RI.To_C_Pointer (asn1SccPayload_Subsystem_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "payload_subsystem_state";
   procedure Startup with Export, Convention => C, Link_Name => "Payload_Subsystem_startup";
   --  Provided interface "Trigger_capture"
   procedure Trigger_capture;
   pragma Export(C, Trigger_capture, "payload_subsystem_PI_Trigger_capture");
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 2;
end Payload_Subsystem;