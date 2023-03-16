with Text_IO; use Text_IO;

with ASN1_Ada_Iterators.Iterators;         use ASN1_Ada_Iterators.Iterators;

package body Gui_Events is

   procedure Process_Event
     (Event        : asn1sccObservable_Event;
      Global_State : in out asn1SccSystem_State)
   is
      Evt : constant asn1sccGui_Event :=
              (case Event.Kind is
                 when Input_Event_Present =>
                    Event.Input_Event.Event.Gui,
                 when Output_Event_Present =>
                    Event.Output_Event.Event.Gui,
                 when others => asn1sccGui_Event_Init);
      --  To transform outputs into a corresponding input message to place
      --  in the recipient queue (with a possibly different name):
      Input_Event : asn1SccObservable_Event (Kind => Input_Event_PRESENT);
   begin
      -- This function executes provided interface events only
      if Event.Kind in No_Event_Present .. System_Startup_Present then
         return;
      end if;
      case Evt.Kind is
         when Msg_IN_Present =>
            case Evt.Msg_In.Kind is
               when Send_Tm_Aoi_PRESENT =>
                  declare
                     Param : asn1SccLocation_Fix_Packet := Evt.Msg_In.Send_Tm_Aoi.Lfp;
                  begin
                     Gui_PI.Send_Tm_Aoi (Lfp => Param, Global_State => Global_State);
                  end;
               when Send_Tm_Mcp_PRESENT =>
                  declare
                     Param : asn1SccMode_Change_Packet := Evt.Msg_In.Send_Tm_Mcp.Mcp;
                  begin
                     Gui_PI.Send_Tm_Mcp (Mcp => Param, Global_State => Global_State);
                  end;
            end case;
         when Msg_OUT_Present =>
            --  Create a input message and place it in the recipient msg queue
            case Evt.Msg_Out.Kind is
                
                when Trig_Aoi_PRESENT =>
                   Input_Event.Input_Event.Source := asn1sccGui;
                   Input_Event.Input_Event.Dest   := asn1sccState_Handler_Entrypoint;
                   Input_Event.Input_Event.Event  :=
                      (Kind => State_Handler_Entrypoint_PRESENT,
                       State_Handler_Entrypoint =>
                          (Kind   => Msg_In_PRESENT,
                           Msg_In => (Kind => Trig_Aoi_PRESENT,
                                      Trig_Aoi =>
                                         (null record))));
                   --  Add to the message queue of the receiving function
                   --  if the receiving queue is not full (otherwise behaviour TBD)
                   if Global_State.State_Handler_Entrypoint_Queue.Length < asn1SccEvents_Ty_length_index (State_Handler_Entrypoint_Queue_Size) then
                      Global_State.State_Handler_Entrypoint_Queue.Length :=
                         Global_State.State_Handler_Entrypoint_Queue.Length + 1;
                      Global_State.State_Handler_Entrypoint_Queue.Data
                        (Global_State.State_Handler_Entrypoint_Queue.Length) := Input_Event;
                   else
                      Put_Line ("[X] Error: Message dropped because input queue of State_Handler_Entrypoint is full");
                   end if;
                when Trig_Mcp_PRESENT =>
                   Input_Event.Input_Event.Source := asn1sccGui;
                   Input_Event.Input_Event.Dest   := asn1sccState_Handler_Entrypoint;
                   Input_Event.Input_Event.Event  :=
                      (Kind => State_Handler_Entrypoint_PRESENT,
                       State_Handler_Entrypoint =>
                          (Kind   => Msg_In_PRESENT,
                           Msg_In => (Kind => Trig_Mcp_PRESENT,
                                      Trig_Mcp =>
                                         (null record))));
                   --  Add to the message queue of the receiving function
                   --  if the receiving queue is not full (otherwise behaviour TBD)
                   if Global_State.State_Handler_Entrypoint_Queue.Length < asn1SccEvents_Ty_length_index (State_Handler_Entrypoint_Queue_Size) then
                      Global_State.State_Handler_Entrypoint_Queue.Length :=
                         Global_State.State_Handler_Entrypoint_Queue.Length + 1;
                      Global_State.State_Handler_Entrypoint_Queue.Data
                        (Global_State.State_Handler_Entrypoint_Queue.Length) := Input_Event;
                   else
                      Put_Line ("[X] Error: Message dropped because input queue of State_Handler_Entrypoint is full");
                   end if;
                when Trig_Pwr_PRESENT =>
                   Input_Event.Input_Event.Source := asn1sccGui;
                   Input_Event.Input_Event.Dest   := asn1sccState_Handler_Entrypoint;
                   Input_Event.Input_Event.Event  :=
                      (Kind => State_Handler_Entrypoint_PRESENT,
                       State_Handler_Entrypoint =>
                          (Kind   => Msg_In_PRESENT,
                           Msg_In => (Kind => Trig_Pwr_PRESENT,
                                      Trig_Pwr =>
                                         (null record))));
                   --  Add to the message queue of the receiving function
                   --  if the receiving queue is not full (otherwise behaviour TBD)
                   if Global_State.State_Handler_Entrypoint_Queue.Length < asn1SccEvents_Ty_length_index (State_Handler_Entrypoint_Queue_Size) then
                      Global_State.State_Handler_Entrypoint_Queue.Length :=
                         Global_State.State_Handler_Entrypoint_Queue.Length + 1;
                      Global_State.State_Handler_Entrypoint_Queue.Data
                        (Global_State.State_Handler_Entrypoint_Queue.Length) := Input_Event;
                   else
                      Put_Line ("[X] Error: Message dropped because input queue of State_Handler_Entrypoint is full");
                   end if;
            end case;
      end case;
   end Process_Event;

   procedure Print_Event (Event : asn1sccGui_Event) is
   begin
      case Event.Kind is
         when Msg_IN_Present =>
            case Event.Msg_In.Kind is
               when Send_Tm_Aoi_PRESENT =>
                 Put ("gui: INPUT Send_Tm_Aoi");
                  Put_Line (" (" & Location_Fix_Packet_Pkg.Image (Event.Msg_In.Send_Tm_Aoi.Lfp) & ")");
               when Send_Tm_Mcp_PRESENT =>
                 Put ("gui: INPUT Send_Tm_Mcp");
                  Put_Line (" (" & Mode_Change_Packet_Pkg.Image (Event.Msg_In.Send_Tm_Mcp.Mcp) & ")");
            end case;
         when Msg_OUT_Present =>
            case Event.Msg_Out.Kind is
                when Trig_Aoi_PRESENT =>
                 Put ("gui: OUTPUT Trig_Aoi");
                  Put_Line ("()");
                when Trig_Mcp_PRESENT =>
                 Put ("gui: OUTPUT Trig_Mcp");
                  Put_Line ("()");
                when Trig_Pwr_PRESENT =>
                 Put ("gui: OUTPUT Trig_Pwr");
                  Put_Line ("()");
            end case;
      end case;
   end Print_Event;

   procedure Exhaust_Interfaces
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean)) is
   begin
     --  Put_Line ("Exhaust interfaces of gui");
      Exhaust_Trig_Aoi (Global_State, Callback);
      Exhaust_Trig_Mcp (Global_State, Callback);
      Exhaust_Trig_Pwr (Global_State, Callback);
   end Exhaust_Interfaces;

   procedure Exhaust_Trig_Aoi
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean))
   is
       Original_State : constant asn1SccSystem_State := Global_State;
       Event          : asn1SccObservable_Event
                         (Kind => Output_Event_PRESENT);
       Limit_Reached  : Boolean;
   begin
      --  Put_Line ("Exhausting interface Trig_Aoi");
      --  Create an event to store as an edge of the state graph
      Event.Output_Event.Source := asn1SccGui;
      Event.Output_Event.Dest   := asn1SccState_Handler_Entrypoint;
      Event.Output_Event.Event  :=
         (Kind => Gui_PRESENT,
          Gui =>
             (Kind   => Msg_OUT_PRESENT,
              Msg_Out => (Kind => Trig_Aoi_PRESENT, others => <>)));

      Callback (Event, Limit_Reached);

      --  Restore previous state
      Global_State := Original_State;
   end Exhaust_Trig_Aoi;
   procedure Exhaust_Trig_Mcp
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean))
   is
       Original_State : constant asn1SccSystem_State := Global_State;
       Event          : asn1SccObservable_Event
                         (Kind => Output_Event_PRESENT);
       Limit_Reached  : Boolean;
   begin
      --  Put_Line ("Exhausting interface Trig_Mcp");
      --  Create an event to store as an edge of the state graph
      Event.Output_Event.Source := asn1SccGui;
      Event.Output_Event.Dest   := asn1SccState_Handler_Entrypoint;
      Event.Output_Event.Event  :=
         (Kind => Gui_PRESENT,
          Gui =>
             (Kind   => Msg_OUT_PRESENT,
              Msg_Out => (Kind => Trig_Mcp_PRESENT, others => <>)));

      Callback (Event, Limit_Reached);

      --  Restore previous state
      Global_State := Original_State;
   end Exhaust_Trig_Mcp;
   procedure Exhaust_Trig_Pwr
      (Global_State : in out asn1SccSystem_State;
       Callback     : access procedure (Event         : asn1SccObservable_Event;
                                        Limit_Reached : out Boolean))
   is
       Original_State : constant asn1SccSystem_State := Global_State;
       Event          : asn1SccObservable_Event
                         (Kind => Output_Event_PRESENT);
       Limit_Reached  : Boolean;
   begin
      --  Put_Line ("Exhausting interface Trig_Pwr");
      --  Create an event to store as an edge of the state graph
      Event.Output_Event.Source := asn1SccGui;
      Event.Output_Event.Dest   := asn1SccState_Handler_Entrypoint;
      Event.Output_Event.Event  :=
         (Kind => Gui_PRESENT,
          Gui =>
             (Kind   => Msg_OUT_PRESENT,
              Msg_Out => (Kind => Trig_Pwr_PRESENT, others => <>)));

      Callback (Event, Limit_Reached);

      --  Restore previous state
      Global_State := Original_State;
   end Exhaust_Trig_Pwr;


end Gui_Events;
