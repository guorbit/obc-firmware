with Interfaces.C;
with PolyORB_HI_Generated.Deployment;
use  PolyORB_HI_Generated.Deployment;
with PolyORB_HI_Generated.Types;
use  PolyORB_HI_Generated.Types;

package X86_Ground_Station_TASTE_Interface is
   --  generated from templates/concurrency_view/ada_wrappers_source/partition.tmplt
   
   --  Package wrapping function gui : manages the call to functions in vm_if.c
   --  Provides mutex to handle protected, cyclic and sporadic provided interfaces
   --  Exports the interface functions called by invoke_ri (vm_...)
   --  generated from templates/concurrency_view/ada_wrappers_source/block.tmplt
   package Gui is
   
      --  This package interfaces with the user code directly
      --  It may contain a protected object if a PI requires mutual exclusion
   
      procedure Init;
   
      --  Protected provided interfaces (incl. Sporadic and cyclics)
      --  from templates/concurrency_view/ada_wrappers_source/pi.tmplt)
      protected Gui_Protected is
         
         procedure Poll;
         procedure Send_Tm_Aoi
            (Lfp : Interfaces.C.char_array; Lfp_Size : Integer);
         procedure Send_Tm_Mcp
            (Mcp : Interfaces.C.char_array; Mcp_Size : Integer);
      end Gui_Protected;
   
      --  Required interfaces (templates/concurrency_view/ada_wrappers_source/ri.tmplt)
      
      procedure Trig_Aoi
         with Export, Convention => C, Link_Name => "vm_gui_trig_aoi";
      procedure Trig_Mcp
         with Export, Convention => C, Link_Name => "vm_gui_trig_mcp";
      procedure Trig_Pwr
         with Export, Convention => C, Link_Name => "vm_gui_trig_pwr";
   end Gui;
   
   
   
   --  generated from templates/concurrency_view/ada_wrappers_source/thread.tmplt
   procedure Gui_Poll_Init renames Gui.Init;
   
   procedure Gui_Poll_Poll
      (dummy_Entity : Entity_Type);
   
   
   --  generated from templates/concurrency_view/ada_wrappers_source/thread.tmplt
   procedure Gui_Send_Tm_Aoi_Init renames Gui.Init;
   
   procedure Gui_Send_Tm_Aoi_Send_Tm_Aoi
      (dummy_Entity : Entity_Type; Param_Buffer : Location_Fix_Packet_Buffer_Impl);
   
   
   --  generated from templates/concurrency_view/ada_wrappers_source/thread.tmplt
   procedure Gui_Send_Tm_Mcp_Init renames Gui.Init;
   
   procedure Gui_Send_Tm_Mcp_Send_Tm_Mcp
      (dummy_Entity : Entity_Type; Param_Buffer : Mode_Change_Packet_Buffer_Impl);
   
end X86_Ground_Station_TASTE_Interface;
