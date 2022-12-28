-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Taste_Basictypes;   use Taste_Basictypes;
with Simulation_Dataview; use Simulation_Dataview;

package State_Handler_Entrypoint_PI is
   --  Interface to the simulation API
   procedure Startup (Global_State : in out asn1SccSystem_State);
   --  Execute only continuous signals (the simulator shall let the user
   --  send intermediate PIs in the queue since they have priority over
   --  continuous signals)
   procedure Continuous_Signals (Global_State : in out asn1SccSystem_State);

   --  Provided interfaces
   procedure Poll_Aoi (Global_State : in out asn1SccSystem_State);
   procedure C_Poll_Aoi
      with Import, Convention => C, Link_Name => "state_handler_entrypoint_PI_poll_aoi";
   
   
   procedure Poll_Mc_Packet (Global_State : in out asn1SccSystem_State);
   procedure C_Poll_Mc_Packet
      with Import, Convention => C, Link_Name => "state_handler_entrypoint_PI_poll_mc_packet";

end State_Handler_Entrypoint_PI;
