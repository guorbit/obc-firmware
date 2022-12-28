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
with Context_tm_provider;
use Context_tm_provider;
with adaasn1rtl;
use adaasn1rtl;
with Tm_Provider_Datamodel; use Tm_Provider_Datamodel;

with Tm_Provider_RI;
package Tm_Provider with Elaborate_Body is
   ctxt : aliased asn1SccTm_provider_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (Tm_Provider_RI.To_C_Pointer (asn1SccTm_Provider_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "tm_provider_state";
   procedure Startup with Export, Convention => C, Link_Name => "Tm_Provider_startup";
   --  Provided interface "request_tm"
   procedure request_tm_Transition;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 1;
end Tm_Provider;