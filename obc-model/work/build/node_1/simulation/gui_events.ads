
with Simulation_DataView; use Simulation_Dataview;

with System_Dataview;  use System_Dataview;   -- definition of the PID type

with Obc_Model_Dataview; use Obc_Model_Dataview;
with Obc_Model_Dataview; use Obc_Model_Dataview;



with Gui_PI;

package Gui_Events is

   procedure Startup (Global_State : in out asn1SccSystem_State)
      renames Gui_PI.Startup;


   --  Process event: execute the provided interface for Input events
   --  Only report output events
   procedure Process_Event (Event        :        asn1sccObservable_Event;
                            Global_State : in out asn1SccSystem_State);

   procedure Print_Event (Event : asn1sccGui_Event);

   --  Helper function to determine the destination function of a GUI event
   -- (e.g. used by the simulator to highlight arrows in the statechart)
   function Get_Event_Dest (Event : access asn1sccObservable_Event) return asn1sccPID is
      (case Event.Output_Event.Event.Gui.Msg_Out.Kind is
          when Trig_Aoi_PRESENT => asn1SccState_Handler_Entrypoint,
          when Trig_Mcp_PRESENT => asn1SccState_Handler_Entrypoint,
          when Trig_Pwr_PRESENT => asn1SccState_Handler_Entrypoint,
          when others => asn1sccEnv)
   with Export, Convention => C, Link_Name => "gui_event_dest";

   --  For exhaustive simulation:
   procedure Exhaust_Interfaces
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean));

private
   procedure Exhaust_Trig_Aoi
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean));
   procedure Exhaust_Trig_Mcp
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean));
   procedure Exhaust_Trig_Pwr
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean));
end Gui_Events;
