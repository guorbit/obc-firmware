with PolyORB_HI.Utils;
use  PolyORB_HI.Utils;
with PolyORB_HI_Generated.Activity,
     PolyORB_HI.Errors;
use  PolyORB_HI_Generated.Activity;

package body X86_Ground_Station_TASTE_Interface is
   --  generated from templates/concurrency_view/ada_wrappers_body/partition.tmplt
   
   --  The package body comes templates/concurrency_view/ada_wrappers_body/block.tmplt
   package body Gui is
   
      --  Initialization function is implemented in C (in vm_if.c)
      procedure Init is
         procedure C_Init
            with Import, Convention => C, Link_Name => "init_gui";
      begin
         C_Init;
      end Init;
   
      --  Protected provided interfaces (incl. Sporadic and cyclics)
      --  from templates/concurrency_view/ada_wrappers_body/pi.tmplt)
      protected body Gui_Protected is
         
         procedure Poll is
            procedure C_Poll
              with Import, Convention => C, Link_Name => "gui_Poll";
         begin
            --  PI has no parameter - could directly call user code (add _PI_ above)
            C_Poll;
         end Poll;
         procedure Send_Tm_Aoi
            (Lfp : Interfaces.C.char_array; Lfp_Size : Integer) is
         
            procedure C_Send_Tm_Aoi
               (Lfp : Interfaces.C.char_array; Lfp_Size : Integer)
         
              with Import, Convention => C, Link_Name => "gui_send_tm_aoi";
         begin
            C_Send_Tm_Aoi
               (Lfp, Lfp_Size);
         end Send_Tm_Aoi;
         procedure Send_Tm_Mcp
            (Mcp : Interfaces.C.char_array; Mcp_Size : Integer) is
         
            procedure C_Send_Tm_Mcp
               (Mcp : Interfaces.C.char_array; Mcp_Size : Integer)
         
              with Import, Convention => C, Link_Name => "gui_send_tm_mcp";
         begin
            C_Send_Tm_Mcp
               (Mcp, Mcp_Size);
         end Send_Tm_Mcp;
      end Gui_Protected;
      --  Unprotected provided interfaces
      --  from templates/concurrency_view/ada_wrappers_body/pi.tmplt
      
      --  End if unprotected interfaces
   
      --  Required interfaces (templates/concurrency_view/ada_wrappers_body/ri.tmplt)
      
      procedure Trig_Aoi
      is
      begin
         --  Sporadic call
         case Get_Task_Id is
            when x86_ground_station_gui_Poll_k =>
               declare
                  Value : gui_Poll_Thread_gui_Poll_others_Interface
                     (gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_Poll_k, Value);
                  Send_Output (x86_ground_station_gui_Poll_k,
                               gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_aoi_k =>
               declare
                  Value : gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Interface
                     (gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_aoi_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_aoi_k,
                               gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_mcp_k =>
               declare
                  Value : gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Interface
                     (gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_mcp_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_mcp_k,
                               gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_aoi),
                               Err);
                 --  TODO : Report the error if any
               end;
            when others => null;
         end case;
      end;
      procedure Trig_Mcp
      is
      begin
         --  Sporadic call
         case Get_Task_Id is
            when x86_ground_station_gui_Poll_k =>
               declare
                  Value : gui_Poll_Thread_gui_Poll_others_Interface
                     (gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_Poll_k, Value);
                  Send_Output (x86_ground_station_gui_Poll_k,
                               gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_aoi_k =>
               declare
                  Value : gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Interface
                     (gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_aoi_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_aoi_k,
                               gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_mcp_k =>
               declare
                  Value : gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Interface
                     (gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_mcp_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_mcp_k,
                               gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_mcp),
                               Err);
                 --  TODO : Report the error if any
               end;
            when others => null;
         end case;
      end;
      procedure Trig_Pwr
      is
      begin
         --  Sporadic call
         case Get_Task_Id is
            when x86_ground_station_gui_Poll_k =>
               declare
                  Value : gui_Poll_Thread_gui_Poll_others_Interface
                     (gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_Poll_k, Value);
                  Send_Output (x86_ground_station_gui_Poll_k,
                               gui_Poll_Thread_gui_Poll_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_aoi_k =>
               declare
                  Value : gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Interface
                     (gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_aoi_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_aoi_k,
                               gui_send_tm_aoi_Thread_gui_send_tm_aoi_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr),
                               Err);
                 --  TODO : Report the error if any
               end;
            when x86_ground_station_gui_send_tm_mcp_k =>
               declare
                  Value : gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Interface
                     (gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr));
                  Err   : PolyORB_Hi.Errors.Error_Kind with Unreferenced;
                  use type PolyORB_HI.Errors.Error_Kind;
               begin
                  Put_Value (x86_ground_station_gui_send_tm_mcp_k, Value);
                  Send_Output (x86_ground_station_gui_send_tm_mcp_k,
                               gui_send_tm_mcp_Thread_gui_send_tm_mcp_others_Port_Type'(OUTPORT_state_handler_entrypoint_trig_pwr),
                               Err);
                 --  TODO : Report the error if any
               end;
            when others => null;
         end case;
      end;
   
   end Gui;
   
   procedure Gui_Poll_Poll
      (dummy_Entity : Entity_Type)
   is
   begin
      Gui.Gui_Protected.Poll;
   end Gui_Poll_Poll;
   procedure Gui_Send_Tm_Aoi_Send_Tm_Aoi
      (dummy_Entity : Entity_Type; Param_Buffer : Location_Fix_Packet_Buffer_Impl)
    is
      Lfp_AdaBuffer : Interfaces.C.char_array (1 .. Interfaces.C.size_t (Param_Buffer.Length)) with Import;
      for Lfp_AdaBuffer'Address use Param_Buffer'Address;
   begin
      Gui.Gui_Protected.Send_Tm_Aoi
         (Lfp_AdaBuffer, Lfp_AdaBuffer'Length);
   end Gui_Send_Tm_Aoi_Send_Tm_Aoi;
   procedure Gui_Send_Tm_Mcp_Send_Tm_Mcp
      (dummy_Entity : Entity_Type; Param_Buffer : Mode_Change_Packet_Buffer_Impl)
    is
      Mcp_AdaBuffer : Interfaces.C.char_array (1 .. Interfaces.C.size_t (Param_Buffer.Length)) with Import;
      for Mcp_AdaBuffer'Address use Param_Buffer'Address;
   begin
      Gui.Gui_Protected.Send_Tm_Mcp
         (Mcp_AdaBuffer, Mcp_AdaBuffer'Length);
   end Gui_Send_Tm_Mcp_Send_Tm_Mcp;
end X86_Ground_Station_TASTE_Interface;
