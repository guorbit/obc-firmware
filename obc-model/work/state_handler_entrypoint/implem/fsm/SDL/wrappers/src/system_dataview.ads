pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
pragma Warnings (Off, "no entities of ""Interfaces"" are referenced");
with Interfaces;
pragma Warnings (On, "no entities of ""Interfaces"" are referenced");

pragma Warnings (Off, "use clause for package ""Interfaces"" has no effect");
use Interfaces;
pragma Warnings (On, "use clause for package ""Interfaces"" has no effect");

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



package System_Dataview with SPARK_Mode
is


subtype asn1SccPID_index_range is Integer range 0..6;
type asn1SccPID is (asn1Scchal, asn1Sccgui, asn1Sccloc_provider, asn1Sccstate_handler_entrypoint, asn1Scctc_provider, asn1Scctm_collection, asn1Sccenv) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccPID use
    (asn1Scchal => 0, asn1Sccgui => 1, asn1Sccloc_provider => 2, asn1Sccstate_handler_entrypoint => 3, asn1Scctc_provider => 4, asn1Scctm_collection => 5, asn1Sccenv => 6);

function asn1SccPID_Equal(val1, val2 : asn1SccPID) return Boolean;

ERR_PID:constant Integer := 166; -- hal | gui | loc-provider | state-handler-entrypoint | tc-provider | tm-collection | env
function asn1SccPID_IsConstraintValid(val : asn1SccPID) return adaasn1rtl.ASN1_RESULT;

function asn1SccPID_Init  return asn1SccPID is
(asn1Scchal);
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide System_Dataview;


end System_Dataview;