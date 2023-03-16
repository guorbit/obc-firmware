with Simulation_Dataview; use Simulation_Dataview;
with ASN1_Iterators.Exhaustive_Simulation; use ASN1_Iterators;
with Simulator;

generic
   type State_With_Observers is tagged private;
   with function Application_State (Full_State : State_With_Observers) return asn1SccSystem_State is <>;
   with procedure Update_State     (Full_State : in out State_With_Observers; Application_State : asn1SccSystem_State) is <>;
   with function Full_State_Init return State_With_Observers is <>;
   with function State_As_String (Full_State : State_With_Observers) return String is <>;
   Run_Observers : access procedure (Full_State : in out State_With_Observers;
                                     Event      : in out asn1sccObservable_Event;
                                     Id         : out Natural;
                                     Success    : out Boolean);
package Simulator_Interface is

   -- The full state depends on the number of observers, which is
   -- not visible here. This is an opaque type, but it is tagged,
   -- and user provides function to read/write the application state
   Full_State : State_With_Observers;
   User_State : aliased asn1SccSystem_State;

   --  Interface to get the system state exported for python calls from ctypes
   function Get_User_State return access asn1SccSystem_State
      is (User_State'Access)
      with Export, Convention => C, Link_Name => "global_state";

   --  Interface to update the system state from Python (or others)
   procedure Set_User_State (New_State : access asn1SccSystem_State)
      with Export, Convention => C, Link_Name => "set_global_state";
   --  Interface to get the system global queue (used by Python UI)
   function Get_Event_Queue return access asn1SccEvents_Ty
      is (Simulator.Events'Access);

   -- Interface to delete an event from the system event queue
   procedure Remove_Pending_Event (Event : access asn1SccObservable_Event)
      with Export, Convention => C, Link_Name => "remove_event";

   procedure Simulation_Startup;

   procedure Process_Event (Event : asn1SccObservable_Event);
   procedure Dispatch_Events;
   procedure Run_Exhaustive_Simulation;

private
   Init : Boolean := False;
   procedure Exhaust_All_Interfaces;

   procedure Print_Event (Event         : asn1SccObservable_Event);
   function Event_As_String (Event : asn1sccObservable_Event)
      return String;
   procedure ES_Callback (Event         : asn1SccObservable_Event;
                          Limit_Reached : out Boolean);

   --  Instantiate the exhaustive simulator
   package ES is new Exhaustive_Simulation
      (Context_Ty       => State_With_Observers,
       Process_Ctxt     => Full_State'Access,
       Event_Ty         => asn1SccObservable_Event,
       Event_As_String  => Event_As_String,
       State_As_String  => State_As_String,
       Print_Event      => Print_Event);

end Simulator_Interface;
