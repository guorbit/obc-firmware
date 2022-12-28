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
with Tm_Collection_Datamodel; use Tm_Collection_Datamodel;

with Tm_Collection_RI;
package Tm_Collection with Elaborate_Body is
   ctxt : aliased asn1SccTm_collection_Context :=
      (Init_Done => False,
       others => <>);
   function Get_State return Chars_Ptr is (Tm_Collection_RI.To_C_Pointer (asn1SccTm_Collection_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "tm_collection_state";
   procedure Startup with Export, Convention => C, Link_Name => "Tm_Collection_startup";
   --  Provided interface "collect_tm"
   procedure collect_tm_Transition;
   --  Synchronous Required Interface "request_tm"
   procedure RI_0_request_tm (Temp : out asn1SccTemperature_Generic; Depl_D : out asn1SccDeployment_Digital; Depl_A : out asn1SccDeployment_Analogue) renames Tm_Collection_RI.request_tm;
   procedure Execute_Transition (Id : Integer);
   CS_Only : constant := 1;
end Tm_Collection;