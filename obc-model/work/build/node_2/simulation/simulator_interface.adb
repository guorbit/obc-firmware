with Text_IO;        use Text_IO;
with Ada.Calendar;   use Ada.Calendar;     -- Time / Clock
with Ada.Containers; use Ada.Containers;   -- Hash_Type

with Simulator;

with Loc_Provider_Events;
with State_Handler_Entrypoint_Events;
with Tc_Provider_Events;
with Tc_Validation_Events;
with Tm_Collection_Events;
with Tm_Provider_Events;

with ASN1_GSER;
--  use ASN1_GSER;

package body Simulator_Interface is


   procedure Set_User_State (New_State : access asn1SccSystem_State) is
   begin
      User_State := New_State.all;
      Update_State (Full_State, User_State);
   end Set_User_State;

   procedure Simulation_Startup
   is
      Startup_Event : constant asn1SccObservable_Event :=
                (Kind           => System_Startup_PRESENT,
                 System_Startup => (null record));
   begin
      Text_IO.Put_Line ("[-] Simulator_Interface startup");

      Full_State := Full_State_Init;

      ES.Backup_Ctxt := Full_State;
      ES.Backup_Hash := ES.State_Hash (Full_State);

      User_State := Application_State (Full_State);

      Loc_Provider_Events.Startup (User_State);
      State_Handler_Entrypoint_Events.Startup (User_State);
      Tc_Provider_Events.Startup (User_State);
      Tc_Validation_Events.Startup (User_State);
      Tm_Collection_Events.Startup (User_State);
      Tm_Provider_Events.Startup (User_State);
      Update_State (Full_State, User_State);

      --  Initialize the state graph with the startup event
      ES.Backup_Ctxt := Full_State;
      ES.Backup_Hash := ES.State_Hash (Full_State);

      ES.Start_Hash := ES.Add_To_Graph (Startup_Event);

      ES.Queue.Append    (ES.Start_Hash);
      ES.Visited.Include (ES.Start_Hash);

      Init := True;
   end Simulation_Startup;

   procedure Run_Exhaustive_Simulation
   is
      Start_Time : constant Time := Clock;
   begin
      if not Init then
         Put_Line ("[X] ERROR: you must call Startup function first");
         return;
      end if;

      while ES.Queue.Length > 0 and ES.Properties.Length < 10 loop
         Full_State :=
            ES.Grafset.Element (Key => ES.Queue.Last_Element).Context;
         User_State := Application_State (Full_State);
         --  Put_Line (State_As_String (Full_State));
         ES.Queue.Delete_Last;
         Exhaust_All_Interfaces;
      end loop;

      if ES.Properties.Length > 0 then
         Put_Line ("[-] Generating MSC");
         ES.Generate_MSC;
      end if;

      Put_Line ("[-] Called" & ES.Count'Img & " interfaces");
      Put_Line ("[-] Visited" & ES.Grafset.Length'Img & " states");
      Put_Line ("[-] Execution time:" & Duration'Image (Clock - Start_Time) & "s.");
   end Run_Exhaustive_Simulation;

   procedure Process_Event (Event : asn1SccObservable_Event) is
   begin
      Put("[-] Process_Event : ");
      Print_Event (Event);
      User_State := Application_State (Full_state);
      case Event.Kind is
         when System_Startup_PRESENT | No_Event_PRESENT | Unhandled_Input_PRESENT => null;
         when Input_Event_PRESENT =>
            case Event.Input_Event.Event.Kind is
               when Loc_Provider_PRESENT             =>
                  Loc_Provider_Events.Process_Event             (Event, User_State);
               when State_Handler_Entrypoint_PRESENT =>
                  State_Handler_Entrypoint_Events.Process_Event (Event, User_State);
               when Tc_Provider_PRESENT              =>
                  Tc_Provider_Events.Process_Event              (Event, User_State);
               when Tc_Validation_PRESENT            =>
                  Tc_Validation_Events.Process_Event            (Event, User_State);
               when Tm_Collection_PRESENT            =>
                  Tm_Collection_Events.Process_Event            (Event, User_State);
               when Tm_Provider_PRESENT              =>
                  Tm_Provider_Events.Process_Event              (Event, User_State);
            end case;
         when Output_Event_PRESENT =>
            case Event.Output_Event.Event.Kind is
               when Loc_Provider_PRESENT             =>
                  Loc_Provider_Events.Process_Event             (Event, User_State);
               when State_Handler_Entrypoint_PRESENT =>
                  State_Handler_Entrypoint_Events.Process_Event (Event, User_State);
               when Tc_Provider_PRESENT              =>
                  Tc_Provider_Events.Process_Event              (Event, User_State);
               when Tc_Validation_PRESENT            =>
                  Tc_Validation_Events.Process_Event            (Event, User_State);
               when Tm_Collection_PRESENT            =>
                  Tm_Collection_Events.Process_Event            (Event, User_State);
               when Tm_Provider_PRESENT              =>
                  Tm_Provider_Events.Process_Event              (Event, User_State);
            end case;
      end case;
      -- User code modified the application state -> place it in the full state
      Update_State (Full_State, User_State);
      --  Uncomment the following line to display the current system state
      --  (useful when debugging the Python interface)
      --  Put_Line ("[-] Simulator.State: " & ASN1_GSER.Image (User_State));

   end Process_Event;

   procedure Dispatch_Events is
   begin
      --  Mostly useful for external (Python) interface: process all events from
      --  the main queue (filled by PI calls) by dispatching OUT event into the
      --  corresponding IN event in the recipent queues
      while Simulator.Events.Length > 0 loop
         Process_Event (Simulator.Pop_Event);
      end loop;
   end Dispatch_Events;

   procedure Remove_Pending_Event (Event : access asn1SccObservable_Event) is
      Pos : Integer := 0;
   begin
      -- Find an event in the queue and delete it (used by Python simulator)
      -- If not found, just return. Some direct events may not be there.
      for I in 1 .. Simulator.Events.Length loop
         exit when Pos > 0;
         if asn1SccObservable_Event_Equal (Event.all, Simulator.Events.Data (I))
         then
            Pos := I;
         end if;
      end loop;
      if Pos > 0 then
         Simulator.Events.Length := Simulator.Events.Length - 1;
         Simulator.Events.Data (1 .. Simulator.Events.Length) :=
            Simulator.Events.Data (1 .. Pos - 1)
            & Simulator.Events.Data (Pos + 1 .. Simulator.Events.Length + 1);
      end if;
      return;
   end Remove_Pending_Event;

   procedure ES_Callback (Event         : asn1SccObservable_Event;
                          Limit_Reached : out Boolean)
   is
      -- This function is called by the <Function>_Events.Exhaust_<RI> code
      -- of each GUI of the system.
      -- These functions generate an Output event for each parameter iteration
      -- This callback is resonsible for processing this event: calling
      -- observers, creating a correponding Input event, execute the PI, etc.
      Unused_Hash    : Hash_Type;
      Current_Event  : aliased asn1sccObservable_Event := Event;
      Id             : Natural;
      Stop_Condition : Boolean := False;
      procedure Next_Event (E : in out asn1sccObservable_Event) is
      begin
         case E.Kind is
            when Input_Event_Present =>
               Put ("[-] Next Event : Input Event");
               Process_Event (E);
               Run_Observers (Full_State,
                              E,
                              Id,
                              Stop_Condition);
            when others =>
               Put ("[-] Next Event : Non-Input Event");
               Run_Observers (Full_State,
                              E,
                              Id,
                              Stop_Condition);
               if not Stop_Condition then
                  Process_Event (E);
               end if;
         end case;
      end Next_Event;
   begin
      --  Flow:
      --   (1) call the observers with the output event
      --   (2) process the event (it may have been altered, even removed)
      --   (3) if there was an event it may have created (pushed) new events
      --       or put events in the message queues of functions
      --       while the list of pending events is not empty:
      --       get the oldest event
      --       call observers with it (they may alter it)
      --       process the event
      --   (4) read the message queues of all functions
      --       (they may have been filled by output event)
      --       place the messages in the main event queue
      --       (that could be using the priorities to decide ordering)
      --       and go back to (4)
      --   (5) Store the possible new state with the input event
      --
      --   "process the event" means:
      --   (a) if event == output: create a corresponding input event,
      --                           place it in the queue of the recipient,
      --   (b) if event == input, execute the pi
      --   (c) if event == no_event, do nothing

      --  for (1) and (2):
      Put_Line ("[-] Callback with state: " & State_As_String (Full_State));
      Next_Event (Current_Event);

      --  for (3):
      loop
         --  Make sure all message queues are drained
         exit when Stop_Condition or (Simulator.Events.Length = 0 and User_State.State_Handler_Entrypoint_Queue.Length = 0);


         loop
            exit when Simulator.Events.Length = 0 or Stop_Condition;
            declare
               E : asn1SccObservable_Event := Simulator.Pop_Event;
            begin
               Next_Event (E);
            end;
         end loop;

         -- for (4):
         if not Stop_Condition then
            for I in 1 .. User_State.State_Handler_Entrypoint_Queue.Length loop
               exit when Stop_Condition;
               declare
                  New_In_Event : aliased asn1sccObservable_Event :=
                          User_State.State_Handler_Entrypoint_Queue.Data (I);
                begin
                   Next_Event (New_In_Event);
                end;
             end loop;
             User_State.State_Handler_Entrypoint_Queue.Length := 0;
             Update_State (Full_State, User_State);
          end if;
      end loop;

      -- Clear the queue of event in case stop conditions interrupted them
      Simulator.Events.Length := 0;

      Put_Line ("[-] Number of states before Add_To_Graph: " & ES.Grafset.Length'Img);

      --  for (5):
      Unused_Hash := ES.Add_To_Graph (Event, Id, Stop_Condition);
      Put_Line ("[-] STATE AT THE END OF CALLBACK: " & State_As_String (Full_State));
      --  Put_Line ("hash: " & Unused_Hash'Img & " In Grafset: " & ES.Grafset.Contains (Key=>Unused_Hash)'Img);
      --  Put_Line ("ES Queue Length : " & ES.Queue.Length'Img);
      Put_Line("[-] Stop Condition = " & Stop_Condition'img);
      --  Put_Line ("ES.Visited.Contains(Hash)? " & ES.Visited.Contains(Unused_Hash)'Img);

      --  Restore the full state (to get the observer in original state for the next iteration
      Full_State := ES.Backup_Ctxt;

      --  Put_Line ("[-] ES_Callback: " & System_State_Pkg.Image (Simulator.State));
      Put_Line ("[-] Number of states after Add_To_Graph: " & ES.Grafset.Length'Img);
      Limit_Reached := ES.Properties.Length >= 10;
   end ES_Callback;

   -- Exhaust Required Interfaces of GUIs (create Output Events)
   procedure Exhaust_All_Interfaces is
   begin
      User_State := Application_State (Full_State);
      ES.Backup_Ctxt := Full_State;
      ES.Backup_Hash := ES.State_Hash (Full_State);
   end Exhaust_All_Interfaces;

   procedure Print_Event (Event : asn1SccObservable_Event) is
   begin
      Put_Line (ASN1_GSER.Image (Event));
--     case Event.Kind is
--        when System_Startup_PRESENT | No_Event_PRESENT | Unhandled_Input_PRESENT => null;
--        when Input_Event_PRESENT =>
--           case Event.Input_Event.Event.Kind is
--              @@TABLE'ALIGN_ON("=>", "(", "Global")@@
--              when Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider_PRESENT =>
--                 Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider_Events.Print_Event (Event => Event.Input_Event.Event.Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider);
--              @@END_TABLE@@
--           end case;
--        when Output_Event_PRESENT =>
--           case Event.Output_Event.Event.Kind is
--              @@TABLE'ALIGN_ON("=>", "(", "Global")@@
--              when Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider_PRESENT =>
--                 Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider_Events.Print_Event (Event => Event.Output_Event.Event.Loc_Provider, State_Handler_Entrypoint, Tc_Provider, Tc_Validation, Tm_Collection, Tm_Provider);
--              @@END_TABLE@@
--           end case;
--     end case;
   end Print_Event;

   function Event_As_String (Event : asn1SccObservable_Event)
      return String is (ASN1_GSER.Image (Event));

   --  Provide the Check_Queue functions needed for continuous signals
   procedure Loc_Provider_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.Loc_Provider_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := Loc_Provider_Events.CS_Barrier;
   end Loc_Provider_Check_Queue;

   procedure State_Handler_Entrypoint_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.State_Handler_Entrypoint_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := State_Handler_Entrypoint_Events.CS_Barrier;
   end State_Handler_Entrypoint_Check_Queue;

   procedure Tc_Provider_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.Tc_Provider_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := Tc_Provider_Events.CS_Barrier;
   end Tc_Provider_Check_Queue;

   procedure Tc_Validation_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.Tc_Validation_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := Tc_Validation_Events.CS_Barrier;
   end Tc_Validation_Check_Queue;

   procedure Tm_Collection_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.Tm_Collection_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := Tm_Collection_Events.CS_Barrier;
   end Tm_Collection_Check_Queue;

   procedure Tm_Provider_Check_Queue (res : out Boolean) is
   begin
      --  res := User_State.Tm_Provider_Queue.Length /= 0;
      --  For simulation use a barrier: continuous signals are evaluated
      --  only from the explicit call
      res := Tm_Provider_Events.CS_Barrier;
   end Tm_Provider_Check_Queue;


begin
   Simulation_Startup;

end Simulator_Interface;
