pragma Warnings (Off);
pragma Ada_95;
with System;
with System.Parameters;
with System.Secondary_Stack;
package ada_main is

   procedure adainit;
   pragma Export (C, adainit, "adainit");

   procedure adafinal;
   pragma Export (C, adafinal, "adafinal");

   type Version_32 is mod 2 ** 32;
   u00001 : constant Version_32 := 16#ef6cdfc6#;
   pragma Export (C, u00001, "adaasn1rtlB");
   u00002 : constant Version_32 := 16#79c9f54c#;
   pragma Export (C, u00002, "adaasn1rtlS");
   u00003 : constant Version_32 := 16#a591dda9#;
   pragma Export (C, u00003, "board_configS");
   u00004 : constant Version_32 := 16#4db87b87#;
   pragma Export (C, u00004, "context_tm_providerB");
   u00005 : constant Version_32 := 16#6481b49f#;
   pragma Export (C, u00005, "context_tm_providerS");
   u00006 : constant Version_32 := 16#744ed3c8#;
   pragma Export (C, u00006, "gui_subtypeB");
   u00007 : constant Version_32 := 16#2c7cf0d4#;
   pragma Export (C, u00007, "gui_subtypeS");
   u00008 : constant Version_32 := 16#0b955f5c#;
   pragma Export (C, u00008, "obc_model_dataviewB");
   u00009 : constant Version_32 := 16#97473482#;
   pragma Export (C, u00009, "obc_model_dataviewS");
   u00010 : constant Version_32 := 16#98ad405b#;
   pragma Export (C, u00010, "state_handler_entrypointB");
   u00011 : constant Version_32 := 16#27c64832#;
   pragma Export (C, u00011, "state_handler_entrypointS");
   u00012 : constant Version_32 := 16#791869c9#;
   pragma Export (C, u00012, "state_handler_entrypoint_datamodelB");
   u00013 : constant Version_32 := 16#54ea2e56#;
   pragma Export (C, u00013, "state_handler_entrypoint_datamodelS");
   u00014 : constant Version_32 := 16#e6ae1c84#;
   pragma Export (C, u00014, "state_handler_entrypoint_riB");
   u00015 : constant Version_32 := 16#366202b4#;
   pragma Export (C, u00015, "state_handler_entrypoint_riS");
   u00016 : constant Version_32 := 16#bfbe33f8#;
   pragma Export (C, u00016, "system_dataviewB");
   u00017 : constant Version_32 := 16#7cc78f2b#;
   pragma Export (C, u00017, "system_dataviewS");
   u00018 : constant Version_32 := 16#473e7ea6#;
   pragma Export (C, u00018, "taste_basictypesB");
   u00019 : constant Version_32 := 16#0bfed639#;
   pragma Export (C, u00019, "taste_basictypesS");
   u00020 : constant Version_32 := 16#050ff2f0#;
   pragma Export (C, u00020, "system__standard_libraryB");
   u00021 : constant Version_32 := 16#4113f22b#;
   pragma Export (C, u00021, "system__standard_libraryS");
   u00022 : constant Version_32 := 16#5ab55268#;
   pragma Export (C, u00022, "interfacesS");
   u00023 : constant Version_32 := 16#76789da1#;
   pragma Export (C, u00023, "adaS");
   u00024 : constant Version_32 := 16#5b4659fa#;
   pragma Export (C, u00024, "ada__charactersS");
   u00025 : constant Version_32 := 16#4b7bb96a#;
   pragma Export (C, u00025, "ada__characters__latin_1S");
   u00026 : constant Version_32 := 16#4635ec04#;
   pragma Export (C, u00026, "systemS");
   u00027 : constant Version_32 := 16#d68fb8f1#;
   pragma Export (C, u00027, "system__bit_opsB");
   u00028 : constant Version_32 := 16#0765e3a3#;
   pragma Export (C, u00028, "system__bit_opsS");
   u00029 : constant Version_32 := 16#f52efeca#;
   pragma Export (C, u00029, "ada__exceptionsB");
   u00030 : constant Version_32 := 16#e824681c#;
   pragma Export (C, u00030, "ada__exceptionsS");
   u00031 : constant Version_32 := 16#5726abed#;
   pragma Export (C, u00031, "ada__exceptions__last_chance_handlerB");
   u00032 : constant Version_32 := 16#41e5552e#;
   pragma Export (C, u00032, "ada__exceptions__last_chance_handlerS");
   u00033 : constant Version_32 := 16#ae860117#;
   pragma Export (C, u00033, "system__soft_linksB");
   u00034 : constant Version_32 := 16#bbca7dc7#;
   pragma Export (C, u00034, "system__soft_linksS");
   u00035 : constant Version_32 := 16#20d205ed#;
   pragma Export (C, u00035, "system__secondary_stackB");
   u00036 : constant Version_32 := 16#bb5d8e68#;
   pragma Export (C, u00036, "system__secondary_stackS");
   u00037 : constant Version_32 := 16#36a16434#;
   pragma Export (C, u00037, "system__parametersB");
   u00038 : constant Version_32 := 16#bea32858#;
   pragma Export (C, u00038, "system__parametersS");
   u00039 : constant Version_32 := 16#ced09590#;
   pragma Export (C, u00039, "system__storage_elementsB");
   u00040 : constant Version_32 := 16#6bf6a600#;
   pragma Export (C, u00040, "system__storage_elementsS");
   u00041 : constant Version_32 := 16#7d395b5e#;
   pragma Export (C, u00041, "system__soft_links__initializeB");
   u00042 : constant Version_32 := 16#5697fc2b#;
   pragma Export (C, u00042, "system__soft_links__initializeS");
   u00043 : constant Version_32 := 16#41837d1e#;
   pragma Export (C, u00043, "system__stack_checkingB");
   u00044 : constant Version_32 := 16#c88a87ec#;
   pragma Export (C, u00044, "system__stack_checkingS");
   u00045 : constant Version_32 := 16#34742901#;
   pragma Export (C, u00045, "system__exception_tableB");
   u00046 : constant Version_32 := 16#1b9b8546#;
   pragma Export (C, u00046, "system__exception_tableS");
   u00047 : constant Version_32 := 16#ce4af020#;
   pragma Export (C, u00047, "system__exceptionsB");
   u00048 : constant Version_32 := 16#2e5681f2#;
   pragma Export (C, u00048, "system__exceptionsS");
   u00049 : constant Version_32 := 16#80916427#;
   pragma Export (C, u00049, "system__exceptions__machineB");
   u00050 : constant Version_32 := 16#3bad9081#;
   pragma Export (C, u00050, "system__exceptions__machineS");
   u00051 : constant Version_32 := 16#aa0563fc#;
   pragma Export (C, u00051, "system__exceptions_debugB");
   u00052 : constant Version_32 := 16#38bf15c0#;
   pragma Export (C, u00052, "system__exceptions_debugS");
   u00053 : constant Version_32 := 16#6c2f8802#;
   pragma Export (C, u00053, "system__img_intB");
   u00054 : constant Version_32 := 16#44ee0cc6#;
   pragma Export (C, u00054, "system__img_intS");
   u00055 : constant Version_32 := 16#39df8c17#;
   pragma Export (C, u00055, "system__tracebackB");
   u00056 : constant Version_32 := 16#181732c0#;
   pragma Export (C, u00056, "system__tracebackS");
   u00057 : constant Version_32 := 16#9ed49525#;
   pragma Export (C, u00057, "system__traceback_entriesB");
   u00058 : constant Version_32 := 16#466e1a74#;
   pragma Export (C, u00058, "system__traceback_entriesS");
   u00059 : constant Version_32 := 16#c2486b24#;
   pragma Export (C, u00059, "system__traceback__symbolicB");
   u00060 : constant Version_32 := 16#c84061d1#;
   pragma Export (C, u00060, "system__traceback__symbolicS");
   u00061 : constant Version_32 := 16#179d7d28#;
   pragma Export (C, u00061, "ada__containersS");
   u00062 : constant Version_32 := 16#701f9d88#;
   pragma Export (C, u00062, "ada__exceptions__tracebackB");
   u00063 : constant Version_32 := 16#20245e75#;
   pragma Export (C, u00063, "ada__exceptions__tracebackS");
   u00064 : constant Version_32 := 16#769e25e6#;
   pragma Export (C, u00064, "interfaces__cB");
   u00065 : constant Version_32 := 16#f60287af#;
   pragma Export (C, u00065, "interfaces__cS");
   u00066 : constant Version_32 := 16#e865e681#;
   pragma Export (C, u00066, "system__bounded_stringsB");
   u00067 : constant Version_32 := 16#31c8cd1d#;
   pragma Export (C, u00067, "system__bounded_stringsS");
   u00068 : constant Version_32 := 16#b018f329#;
   pragma Export (C, u00068, "system__crtlS");
   u00069 : constant Version_32 := 16#2260731f#;
   pragma Export (C, u00069, "system__dwarf_linesB");
   u00070 : constant Version_32 := 16#5f137e60#;
   pragma Export (C, u00070, "system__dwarf_linesS");
   u00071 : constant Version_32 := 16#8f637df8#;
   pragma Export (C, u00071, "ada__characters__handlingB");
   u00072 : constant Version_32 := 16#3b3f6154#;
   pragma Export (C, u00072, "ada__characters__handlingS");
   u00073 : constant Version_32 := 16#e6d4fa36#;
   pragma Export (C, u00073, "ada__stringsS");
   u00074 : constant Version_32 := 16#96df1a3f#;
   pragma Export (C, u00074, "ada__strings__mapsB");
   u00075 : constant Version_32 := 16#1e526bec#;
   pragma Export (C, u00075, "ada__strings__mapsS");
   u00076 : constant Version_32 := 16#72b39087#;
   pragma Export (C, u00076, "system__unsigned_typesS");
   u00077 : constant Version_32 := 16#92f05f13#;
   pragma Export (C, u00077, "ada__strings__maps__constantsS");
   u00078 : constant Version_32 := 16#a0d3d22b#;
   pragma Export (C, u00078, "system__address_imageB");
   u00079 : constant Version_32 := 16#e7d9713e#;
   pragma Export (C, u00079, "system__address_imageS");
   u00080 : constant Version_32 := 16#ec78c2bf#;
   pragma Export (C, u00080, "system__img_unsB");
   u00081 : constant Version_32 := 16#ed47ac70#;
   pragma Export (C, u00081, "system__img_unsS");
   u00082 : constant Version_32 := 16#d7aac20c#;
   pragma Export (C, u00082, "system__ioB");
   u00083 : constant Version_32 := 16#d8771b4b#;
   pragma Export (C, u00083, "system__ioS");
   u00084 : constant Version_32 := 16#f790d1ef#;
   pragma Export (C, u00084, "system__mmapB");
   u00085 : constant Version_32 := 16#7c445363#;
   pragma Export (C, u00085, "system__mmapS");
   u00086 : constant Version_32 := 16#92d882c5#;
   pragma Export (C, u00086, "ada__io_exceptionsS");
   u00087 : constant Version_32 := 16#0cdaa54a#;
   pragma Export (C, u00087, "system__mmap__os_interfaceB");
   u00088 : constant Version_32 := 16#82f29877#;
   pragma Export (C, u00088, "system__mmap__os_interfaceS");
   u00089 : constant Version_32 := 16#834dfe5e#;
   pragma Export (C, u00089, "system__mmap__unixS");
   u00090 : constant Version_32 := 16#68267aea#;
   pragma Export (C, u00090, "system__os_libB");
   u00091 : constant Version_32 := 16#4542b55d#;
   pragma Export (C, u00091, "system__os_libS");
   u00092 : constant Version_32 := 16#d1060688#;
   pragma Export (C, u00092, "system__case_utilB");
   u00093 : constant Version_32 := 16#623c85d3#;
   pragma Export (C, u00093, "system__case_utilS");
   u00094 : constant Version_32 := 16#2a8e89ad#;
   pragma Export (C, u00094, "system__stringsB");
   u00095 : constant Version_32 := 16#2623c091#;
   pragma Export (C, u00095, "system__stringsS");
   u00096 : constant Version_32 := 16#ef6ff0b4#;
   pragma Export (C, u00096, "system__object_readerB");
   u00097 : constant Version_32 := 16#0b06497e#;
   pragma Export (C, u00097, "system__object_readerS");
   u00098 : constant Version_32 := 16#1a74a354#;
   pragma Export (C, u00098, "system__val_lliB");
   u00099 : constant Version_32 := 16#dc110aa4#;
   pragma Export (C, u00099, "system__val_lliS");
   u00100 : constant Version_32 := 16#afdbf393#;
   pragma Export (C, u00100, "system__val_lluB");
   u00101 : constant Version_32 := 16#0841c7f5#;
   pragma Export (C, u00101, "system__val_lluS");
   u00102 : constant Version_32 := 16#27b600b2#;
   pragma Export (C, u00102, "system__val_utilB");
   u00103 : constant Version_32 := 16#ea955afa#;
   pragma Export (C, u00103, "system__val_utilS");
   u00104 : constant Version_32 := 16#d7bf3f29#;
   pragma Export (C, u00104, "system__exception_tracesB");
   u00105 : constant Version_32 := 16#62eacc9e#;
   pragma Export (C, u00105, "system__exception_tracesS");
   u00106 : constant Version_32 := 16#8c33a517#;
   pragma Export (C, u00106, "system__wch_conB");
   u00107 : constant Version_32 := 16#5d48ced6#;
   pragma Export (C, u00107, "system__wch_conS");
   u00108 : constant Version_32 := 16#9721e840#;
   pragma Export (C, u00108, "system__wch_stwB");
   u00109 : constant Version_32 := 16#7059e2d7#;
   pragma Export (C, u00109, "system__wch_stwS");
   u00110 : constant Version_32 := 16#a831679c#;
   pragma Export (C, u00110, "system__wch_cnvB");
   u00111 : constant Version_32 := 16#52ff7425#;
   pragma Export (C, u00111, "system__wch_cnvS");
   u00112 : constant Version_32 := 16#ece6fdb6#;
   pragma Export (C, u00112, "system__wch_jisB");
   u00113 : constant Version_32 := 16#d28f6d04#;
   pragma Export (C, u00113, "system__wch_jisS");
   u00114 : constant Version_32 := 16#cd2959fb#;
   pragma Export (C, u00114, "ada__numericsS");
   u00115 : constant Version_32 := 16#273384e4#;
   pragma Export (C, u00115, "system__img_enum_newB");
   u00116 : constant Version_32 := 16#2779eac4#;
   pragma Export (C, u00116, "system__img_enum_newS");
   u00117 : constant Version_32 := 16#3e932977#;
   pragma Export (C, u00117, "system__img_lluB");
   u00118 : constant Version_32 := 16#3b7a9044#;
   pragma Export (C, u00118, "system__img_lluS");
   u00119 : constant Version_32 := 16#8aa4f090#;
   pragma Export (C, u00119, "system__img_realB");
   u00120 : constant Version_32 := 16#819dbde6#;
   pragma Export (C, u00120, "system__img_realS");
   u00121 : constant Version_32 := 16#42a257f7#;
   pragma Export (C, u00121, "system__fat_llfS");
   u00122 : constant Version_32 := 16#1b28662b#;
   pragma Export (C, u00122, "system__float_controlB");
   u00123 : constant Version_32 := 16#a6c9af38#;
   pragma Export (C, u00123, "system__float_controlS");
   u00124 : constant Version_32 := 16#16458a73#;
   pragma Export (C, u00124, "system__powten_tableS");
   u00125 : constant Version_32 := 16#69f6ee6b#;
   pragma Export (C, u00125, "interfaces__c__stringsB");
   u00126 : constant Version_32 := 16#603c1c44#;
   pragma Export (C, u00126, "interfaces__c__stringsS");
   u00127 : constant Version_32 := 16#935938d8#;
   pragma Export (C, u00127, "system__memoryB");
   u00128 : constant Version_32 := 16#1f488a30#;
   pragma Export (C, u00128, "system__memoryS");

   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  ada.characters%s
   --  ada.characters.latin_1%s
   --  interfaces%s
   --  system%s
   --  system.case_util%s
   --  system.case_util%b
   --  system.float_control%s
   --  system.float_control%b
   --  system.img_enum_new%s
   --  system.img_enum_new%b
   --  system.img_int%s
   --  system.img_int%b
   --  system.io%s
   --  system.io%b
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  system.powten_table%s
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.strings%s
   --  system.strings%b
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  system.unsigned_types%s
   --  system.fat_llf%s
   --  system.img_llu%s
   --  system.img_llu%b
   --  system.img_uns%s
   --  system.img_uns%b
   --  system.img_real%s
   --  system.img_real%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%s
   --  system.wch_cnv%b
   --  system.traceback%s
   --  system.traceback%b
   --  system.secondary_stack%s
   --  system.standard_library%s
   --  system.exception_traces%s
   --  ada.exceptions%s
   --  system.wch_stw%s
   --  system.val_util%s
   --  system.val_llu%s
   --  system.val_lli%s
   --  system.os_lib%s
   --  ada.characters.handling%s
   --  ada.exceptions.traceback%s
   --  ada.exceptions.traceback%b
   --  system.soft_links%s
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.io_exceptions%s
   --  ada.strings%s
   --  ada.containers%s
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.soft_links.initialize%s
   --  system.soft_links.initialize%b
   --  system.soft_links%b
   --  system.secondary_stack%b
   --  system.address_image%s
   --  system.bounded_strings%s
   --  ada.exceptions.last_chance_handler%s
   --  system.bit_ops%s
   --  system.exceptions_debug%s
   --  system.exceptions_debug%b
   --  system.exception_traces%b
   --  system.memory%s
   --  system.memory%b
   --  system.wch_stw%b
   --  system.val_util%b
   --  system.val_llu%b
   --  system.val_lli%b
   --  system.os_lib%b
   --  ada.strings.maps%s
   --  ada.strings.maps.constants%s
   --  ada.characters.handling%b
   --  interfaces.c%s
   --  system.exceptions.machine%s
   --  system.exceptions.machine%b
   --  system.address_image%b
   --  system.bounded_strings%b
   --  ada.exceptions.last_chance_handler%b
   --  system.bit_ops%b
   --  system.standard_library%b
   --  system.mmap%s
   --  ada.strings.maps%b
   --  interfaces.c%b
   --  system.object_reader%s
   --  system.dwarf_lines%s
   --  system.dwarf_lines%b
   --  system.mmap.unix%s
   --  system.mmap.os_interface%s
   --  system.mmap%b
   --  system.traceback.symbolic%s
   --  system.traceback.symbolic%b
   --  ada.exceptions%b
   --  system.object_reader%b
   --  system.mmap.os_interface%b
   --  ada.numerics%s
   --  interfaces.c.strings%s
   --  interfaces.c.strings%b
   --  board_config%s
   --  adaasn1rtl%s
   --  adaasn1rtl%b
   --  obc_model_dataview%s
   --  obc_model_dataview%b
   --  context_tm_provider%s
   --  context_tm_provider%b
   --  gui_subtype%s
   --  gui_subtype%b
   --  state_handler_entrypoint_datamodel%s
   --  state_handler_entrypoint_datamodel%b
   --  system_dataview%s
   --  system_dataview%b
   --  taste_basictypes%s
   --  taste_basictypes%b
   --  state_handler_entrypoint_ri%s
   --  state_handler_entrypoint_ri%b
   --  state_handler_entrypoint%s
   --  state_handler_entrypoint%b
   --  END ELABORATION ORDER

end ada_main;
