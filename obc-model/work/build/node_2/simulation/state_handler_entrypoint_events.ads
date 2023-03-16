
with Simulation_DataView; use Simulation_Dataview;

with System_Dataview;  use System_Dataview;   -- definition of the PID type



with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;

with State_Handler_Entrypoint_PI;

package State_Handler_Entrypoint_Events is

   procedure Startup (Global_State : in out asn1SccSystem_State)
      renames State_Handler_Entrypoint_PI.Startup;

   --  Barrier for the evaluation of continuous signals when Check_Queue is called
   --  Value true ensures that they are not evaluated automatically after the
   --  execution of a transition (it means: there is a message in the queue, and
   --  they have priority). When user in the simulator send the "Input none"
   --  event, it is sent to false, so that continuous signals are evaluated on demand
   --  allowing to address all cases (leaving time to the user or model checker to
   --  place a message in the queue and skip continuous signals).
   CS_Barrier : Boolean := True;

   --  Process event: execute the provided interface for Input events
   --  Only report output events
   procedure Process_Event (Event        :        asn1sccObservable_Event;
                            Global_State : in out asn1SccSystem_State);

   procedure Print_Event (Event : asn1sccState_Handler_Entrypoint_Event);

end State_Handler_Entrypoint_Events;
