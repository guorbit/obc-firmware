
with Simulation_DataView; use Simulation_Dataview;

with System_Dataview;  use System_Dataview;   -- definition of the PID type



with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;

with Tm_Collection_PI;

package Tm_Collection_Events is

   procedure Startup (Global_State : in out asn1SccSystem_State)
      renames Tm_Collection_PI.Startup;


   --  Process event: execute the provided interface for Input events
   --  Only report output events
   procedure Process_Event (Event        :        asn1sccObservable_Event;
                            Global_State : in out asn1SccSystem_State);

   procedure Print_Event (Event : asn1sccTm_Collection_Event);

end Tm_Collection_Events;
