
with Simulation_DataView; use Simulation_Dataview;

with System_Dataview;  use System_Dataview;   -- definition of the PID type




with Tc_Validation_PI;

package Tc_Validation_Events is

   procedure Startup (Global_State : in out asn1SccSystem_State)
      renames Tc_Validation_PI.Startup;


   --  Process event: execute the provided interface for Input events
   --  Only report output events
   procedure Process_Event (Event        :        asn1sccObservable_Event;
                            Global_State : in out asn1SccSystem_State);

   procedure Print_Event (Event : asn1sccTc_Validation_Event);

end Tc_Validation_Events;
