--  DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
--  Generated by TASTE (Kazoo template templates/skeletons/ada-ri-source/function.tmplt)
--  2022-12-01 23:52:10
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Taste_Basictypes;   use Taste_Basictypes;
with adaasn1rtl;
with Interfaces.C.Strings; use Interfaces.C.Strings;

package Tm_Provider_RI is

   

   procedure Check_Queue (Res : out adaasn1rtl.Asn1Boolean)
      with Import, Convention => C, Link_Name => "tm_provider_check_queue";

   --  Return the SDL state as a char * for the MSC tracing function
   function To_C_Pointer (State_As_String : String) return Chars_Ptr is
      (New_String (State_As_String));
end Tm_Provider_RI;
