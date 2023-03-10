-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- (Generated by TASTE/Kazoo - $TOOL_SRC/kazoo/templates/glue/language_wrappers/simu_pi_adb/function.tmplt)
package body Loc_Provider_PI is

   procedure Update_States_For_Synchronous_Calls (Global_State : asn1SccSystem_State) is
   begin
      --  No synchronous RIs are connected to this function
      null;
   end Update_States_For_Synchronous_Calls;

   procedure Update_Global_State_After_Synchronous_Calls (Global_State : in out asn1SccSystem_State)  is
   begin
      --  No synchronous RIs are connected to this function
      null;
   end Update_Global_State_After_Synchronous_Calls;

   procedure Startup (Global_State : in out asn1SccSystem_State) is
   begin
      --  Initialize the global state after startup function has run
      null;
   end Startup;

   procedure Continuous_Signals (Global_State : in out asn1SccSystem_State) is
   begin
     null;
   end Continuous_Signals;

   --  Provided interfaces
   procedure Request_Loc
      (Global_State : in out asn1SccSystem_State;
      Lfp :    out asn1SccLocation_Fix_Packet) is
   begin
      --  If user code calls synchronous RIs, set their state too
      Update_States_For_Synchronous_Calls (Global_State);
      C_Request_Loc
         (Lfp => Lfp);
   end Request_Loc;

end Loc_Provider_PI;
