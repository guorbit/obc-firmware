-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Taste_Basictypes;   use Taste_Basictypes;
with Simulation_Dataview; use Simulation_Dataview;

package Tc_Provider_PI is
   --  Interface to the simulation API
   procedure Startup (Global_State : in out asn1SccSystem_State);
   --  Execute only continuous signals (the simulator shall let the user
   --  send intermediate PIs in the queue since they have priority over
   --  continuous signals)
   procedure Continuous_Signals (Global_State : in out asn1SccSystem_State);

   --  Provided interfaces
   procedure Request_Tc
      (Global_State : in out asn1SccSystem_State;
      Mcp :    out asn1SccMode_Change_Packet);
   
   --  Interface to the C implementation of the interface
   procedure C_Request_Tc
     (Mcp :    out asn1SccMode_Change_Packet)
   
      with Import, Convention => C, Link_Name => "tc_provider_PI_request_tc";

end Tc_Provider_PI;
