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
with Loc_Provider_Datamodel; use Loc_Provider_Datamodel;

with Loc_Provider_RI;
package Loc_Provider with Elaborate_Body is
   ctxt : aliased asn1SccLoc_provider_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (Loc_Provider_RI.To_C_Pointer (asn1SccLoc_Provider_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "loc_provider_state";
   procedure Startup with Export, Convention => C, Link_Name => "Loc_Provider_startup";
   --  Provided interface "request_loc"
   procedure request_loc_Transition;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 2;
end Loc_Provider;