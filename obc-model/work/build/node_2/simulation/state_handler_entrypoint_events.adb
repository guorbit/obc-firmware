with Text_IO; use Text_IO;

with ASN1_Ada_Iterators.Iterators;         use ASN1_Ada_Iterators.Iterators;

package body State_Handler_Entrypoint_Events is

   procedure Process_Event
     (Event        : asn1sccObservable_Event;
      Global_State : in out asn1SccSystem_State)
   is
      Evt : constant asn1sccState_Handler_Entrypoint_Event :=
              (case Event.Kind is
                 when Input_Event_Present =>
                    Event.Input_Event.Event.State_Handler_Entrypoint,
                 when Output_Event_Present =>
                    Event.Output_Event.Event.State_Handler_Entrypoint,
                 when others => asn1sccState_Handler_Entrypoint_Event_Init);
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
               when Input_None_PRESENT =>
                  CS_Barrier := False;   -- Force Check_Queue to pass
                  State_Handler_Entrypoint_PI.Continuous_Signals (Global_State);
                  CS_Barrier := True;
               when Poll_Aoi_PRESENT =>
                  State_Handler_Entrypoint_PI.Poll_Aoi (Global_State => Global_State);
               when Poll_Mcp_PRESENT =>
                  State_Handler_Entrypoint_PI.Poll_Mcp (Global_State => Global_State);
               when Toggle_Pwr_PRESENT =>
                  State_Handler_Entrypoint_PI.Toggle_Pwr (Global_State => Global_State);
               when Trig_Aoi_PRESENT =>
                  State_Handler_Entrypoint_PI.Trig_Aoi (Global_State => Global_State);
               when Trig_Mcp_PRESENT =>
                  State_Handler_Entrypoint_PI.Trig_Mcp (Global_State => Global_State);
               when Trig_Pwr_PRESENT =>
                  State_Handler_Entrypoint_PI.Trig_Pwr (Global_State => Global_State);
            end case;
         when Msg_OUT_Present =>
            --  Create a input message and place it in the recipient msg queue
            case Evt.Msg_Out.Kind is
                
                --  Synchronous calls are not intercepted for the moment
                --  when Collect_Tm_PRESENT =>
                --   Put_Line ("[collect_tm] PROCEDURE CALL OF collect_tm");
                --  Synchronous calls are not intercepted for the moment
                --  when Request_Loc_PRESENT =>
                --   Put_Line ("[request_loc] PROCEDURE CALL OF request_loc");
                --  Synchronous calls are not intercepted for the moment
                --  when Request_Tc_PRESENT =>
                --   Put_Line ("[request_tc] PROCEDURE CALL OF request_tc");
                when Send_Tm_Aoi_PRESENT =>
                   null;
                   --  message is sent to the environment, which has no input queue
                   --  How to process this event in the simulator is TBD
                   --  (the model checker sends it to the observers before it is dropped here)
                   --  Put_Line ("[-] Message to environment: Send_Tm_Aoi");
                when Send_Tm_Mcp_PRESENT =>
                   null;
                   --  message is sent to the environment, which has no input queue
                   --  How to process this event in the simulator is TBD
                   --  (the model checker sends it to the observers before it is dropped here)
                   --  Put_Line ("[-] Message to environment: Send_Tm_Mcp");
                --  Synchronous calls are not intercepted for the moment
                --  when Validate_Mc_Vs_Tm_PRESENT =>
                --   Put_Line ("[validate_mc_vs_tm] PROCEDURE CALL OF validate_mc_vs_tm");
            end case;
      end case;
   end Process_Event;

   procedure Print_Event (Event : asn1sccState_Handler_Entrypoint_Event) is
   begin
      case Event.Kind is
         when Msg_IN_Present =>
            case Event.Msg_In.Kind is
               when Input_None_PRESENT =>
                  Put_Line ("state_handler_entrypoint: continuous signals");
               when Poll_Aoi_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Poll_Aoi");
                  Put_Line ("()");
               when Poll_Mcp_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Poll_Mcp");
                  Put_Line ("()");
               when Toggle_Pwr_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Toggle_Pwr");
                  Put_Line ("()");
               when Trig_Aoi_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Trig_Aoi");
                  Put_Line ("()");
               when Trig_Mcp_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Trig_Mcp");
                  Put_Line ("()");
               when Trig_Pwr_PRESENT =>
                 Put ("state_handler_entrypoint: INPUT Trig_Pwr");
                  Put_Line ("()");
            end case;
         when Msg_OUT_Present =>
            case Event.Msg_Out.Kind is
                when Send_Tm_Aoi_PRESENT =>
                 Put ("state_handler_entrypoint: OUTPUT Send_Tm_Aoi");
                  Put_Line (" (" & Location_Fix_Packet_Pkg.Image (Event.Msg_Out.Send_Tm_Aoi.Lfp) & ")");
                when Send_Tm_Mcp_PRESENT =>
                 Put ("state_handler_entrypoint: OUTPUT Send_Tm_Mcp");
                  Put_Line (" (" & Mode_Change_Packet_Pkg.Image (Event.Msg_Out.Send_Tm_Mcp.Mcp) & ")");
                --  Synchronous calls are not intercepted for the moment
                --  when Collect_Tm_PRESENT =>
                --     Put_Line ("state_handler_entrypoint : CALL collect_tm");
                --  Synchronous calls are not intercepted for the moment
                --  when Request_Loc_PRESENT =>
                --     Put_Line ("state_handler_entrypoint : CALL request_loc");
                --  Synchronous calls are not intercepted for the moment
                --  when Request_Tc_PRESENT =>
                --     Put_Line ("state_handler_entrypoint : CALL request_tc");
                --  Synchronous calls are not intercepted for the moment
                --  when Validate_Mc_Vs_Tm_PRESENT =>
                --     Put_Line ("state_handler_entrypoint : CALL validate_mc_vs_tm");
            end case;
      end case;
   end Print_Event;



end State_Handler_Entrypoint_Events;
