-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Taste_Basictypes;   use Taste_Basictypes;
with Simulation_Dataview; use Simulation_Dataview;

package Tm_Collection_PI is
   --  Interface to the simulation API
   procedure Startup (Global_State : in out asn1SccSystem_State);
   --  Execute only continuous signals (the simulator shall let the user
   --  send intermediate PIs in the queue since they have priority over
   --  continuous signals)
   procedure Continuous_Signals (Global_State : in out asn1SccSystem_State);

   --  Provided interfaces
   procedure Collect_Tm (Global_State : in out asn1SccSystem_State);
   procedure C_Collect_Tm
      with Import, Convention => C, Link_Name => "tm_collection_PI_collect_tm";

end Tm_Collection_PI;
