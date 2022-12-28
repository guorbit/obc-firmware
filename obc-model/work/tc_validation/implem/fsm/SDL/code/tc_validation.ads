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
with Tc_Validation_Datamodel; use Tc_Validation_Datamodel;

with Tc_Validation_RI;
package Tc_Validation with Elaborate_Body is
   ctxt : aliased asn1SccTc_validation_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (Tc_Validation_RI.To_C_Pointer (asn1SccTc_Validation_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "tc_validation_state";
   procedure Startup with Export, Convention => C, Link_Name => "Tc_Validation_startup";
   --  Provided interface "validate_mc_vs_tm"
   procedure validate_mc_vs_tm_Transition;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 1;
end Tc_Validation;