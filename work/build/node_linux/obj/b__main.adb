pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__main.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__main.adb");
pragma Suppress (Overflow_Check);

package body ada_main is

   E091 : Short_Integer; pragma Import (Ada, E091, "system__os_lib_E");
   E034 : Short_Integer; pragma Import (Ada, E034, "system__soft_links_E");
   E046 : Short_Integer; pragma Import (Ada, E046, "system__exception_table_E");
   E086 : Short_Integer; pragma Import (Ada, E086, "ada__io_exceptions_E");
   E073 : Short_Integer; pragma Import (Ada, E073, "ada__strings_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__containers_E");
   E048 : Short_Integer; pragma Import (Ada, E048, "system__exceptions_E");
   E042 : Short_Integer; pragma Import (Ada, E042, "system__soft_links__initialize_E");
   E075 : Short_Integer; pragma Import (Ada, E075, "ada__strings__maps_E");
   E077 : Short_Integer; pragma Import (Ada, E077, "ada__strings__maps__constants_E");
   E065 : Short_Integer; pragma Import (Ada, E065, "interfaces__c_E");
   E097 : Short_Integer; pragma Import (Ada, E097, "system__object_reader_E");
   E070 : Short_Integer; pragma Import (Ada, E070, "system__dwarf_lines_E");
   E060 : Short_Integer; pragma Import (Ada, E060, "system__traceback__symbolic_E");
   E114 : Short_Integer; pragma Import (Ada, E114, "ada__numerics_E");
   E126 : Short_Integer; pragma Import (Ada, E126, "interfaces__c__strings_E");
   E002 : Short_Integer; pragma Import (Ada, E002, "adaasn1rtl_E");
   E009 : Short_Integer; pragma Import (Ada, E009, "obc_model_dataview_E");
   E005 : Short_Integer; pragma Import (Ada, E005, "context_tm_provider_E");
   E007 : Short_Integer; pragma Import (Ada, E007, "gui_subtype_E");
   E013 : Short_Integer; pragma Import (Ada, E013, "state_handler_entrypoint_datamodel_E");
   E017 : Short_Integer; pragma Import (Ada, E017, "system_dataview_E");
   E019 : Short_Integer; pragma Import (Ada, E019, "taste_basictypes_E");
   E015 : Short_Integer; pragma Import (Ada, E015, "state_handler_entrypoint_ri_E");
   E011 : Short_Integer; pragma Import (Ada, E011, "state_handler_entrypoint_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (C, s_stalib_adafinal, "system__standard_library__adafinal");

      procedure Runtime_Finalize;
      pragma Import (C, Runtime_Finalize, "__gnat_runtime_finalize");

   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      Runtime_Finalize;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Default_Secondary_Stack_Size : System.Parameters.Size_Type;
      pragma Import (C, Default_Secondary_Stack_Size, "__gnat_default_ss_size");
      Leap_Seconds_Support : Integer;
      pragma Import (C, Leap_Seconds_Support, "__gl_leap_seconds_support");
      Bind_Env_Addr : System.Address;
      pragma Import (C, Bind_Env_Addr, "__gl_bind_env_addr");

      procedure Runtime_Initialize (Install_Handler : Integer);
      pragma Import (C, Runtime_Initialize, "__gnat_runtime_initialize");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
      Binder_Sec_Stacks_Count : Natural;
      pragma Import (Ada, Binder_Sec_Stacks_Count, "__gnat_binder_ss_count");
      Default_Sized_SS_Pool : System.Address;
      pragma Import (Ada, Default_Sized_SS_Pool, "__gnat_default_ss_pool");

   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;
      Leap_Seconds_Support := 0;

      ada_main'Elab_Body;
      Default_Secondary_Stack_Size := System.Parameters.Runtime_Default_Sec_Stack_Size;
      Binder_Sec_Stacks_Count := 1;
      Default_Sized_SS_Pool := Sec_Default_Sized_Stacks'Address;

      Runtime_Initialize (1);

      Finalize_Library_Objects := null;

      if E034 = 0 then
         System.Soft_Links'Elab_Spec;
      end if;
      if E046 = 0 then
         System.Exception_Table'Elab_Body;
      end if;
      E046 := E046 + 1;
      if E086 = 0 then
         Ada.Io_Exceptions'Elab_Spec;
      end if;
      E086 := E086 + 1;
      if E073 = 0 then
         Ada.Strings'Elab_Spec;
      end if;
      E073 := E073 + 1;
      if E061 = 0 then
         Ada.Containers'Elab_Spec;
      end if;
      E061 := E061 + 1;
      if E048 = 0 then
         System.Exceptions'Elab_Spec;
      end if;
      E048 := E048 + 1;
      if E042 = 0 then
         System.Soft_Links.Initialize'Elab_Body;
      end if;
      E042 := E042 + 1;
      E034 := E034 + 1;
      if E091 = 0 then
         System.Os_Lib'Elab_Body;
      end if;
      E091 := E091 + 1;
      if E075 = 0 then
         Ada.Strings.Maps'Elab_Spec;
      end if;
      if E077 = 0 then
         Ada.Strings.Maps.Constants'Elab_Spec;
      end if;
      E077 := E077 + 1;
      if E065 = 0 then
         Interfaces.C'Elab_Spec;
      end if;
      E075 := E075 + 1;
      E065 := E065 + 1;
      if E097 = 0 then
         System.Object_Reader'Elab_Spec;
      end if;
      if E070 = 0 then
         System.Dwarf_Lines'Elab_Spec;
      end if;
      E070 := E070 + 1;
      if E060 = 0 then
         System.Traceback.Symbolic'Elab_Body;
      end if;
      E060 := E060 + 1;
      E097 := E097 + 1;
      if E114 = 0 then
         Ada.Numerics'Elab_Spec;
      end if;
      E114 := E114 + 1;
      if E126 = 0 then
         Interfaces.C.Strings'Elab_Spec;
      end if;
      E126 := E126 + 1;
      E002 := E002 + 1;
      E009 := E009 + 1;
      E005 := E005 + 1;
      E007 := E007 + 1;
      E013 := E013 + 1;
      E017 := E017 + 1;
      E019 := E019 + 1;
      E015 := E015 + 1;
      if E011 = 0 then
         State_Handler_Entrypoint'Elab_Body;
      end if;
      E011 := E011 + 1;
   end adainit;

--  BEGIN Object file/option list
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/board_config.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/adaasn1rtl.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/obc_model_dataview.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/context_tm_provider.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/gui_subtype.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/state_handler_entrypoint_datamodel.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/system_dataview.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/taste_basictypes.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/state_handler_entrypoint_ri.o
   --   /home/taste/obc-model/obc-model/work/build/node_linux/obj/state_handler_entrypoint.o
   --   -L/home/taste/obc-model/obc-model/work/build/node_linux/obj/
   --   -L/home/taste/obc-model/obc-model/work/build/node_linux/obj/
   --   -L/usr/lib/gcc/x86_64-linux-gnu/8/adalib/
   --   -shared
   --   -lgnat-8
   --   -ldl
--  END Object file/option list   

end ada_main;
