divert(-1)
/*
*  This m4 file uses the following diverts:
*    1 for overall structure
*    5 for cast functions for GUI parameter subtypes
*    7 for num functions on Enum types
*    10 for signals
*    20 for functions
*/dnl
include(templates.m4)
divert(-1)
define(`m4_gui_trig_aoi',`state_handler_entrypoint_trig_aoi')dnl
define(`m4_gui_trig_aoi_provider',`state_handler_entrypoint')dnl
define(`m4_gui_trig_mcp',`state_handler_entrypoint_trig_mcp')dnl
define(`m4_gui_trig_mcp_provider',`state_handler_entrypoint')dnl
define(`m4_gui_trig_pwr',`state_handler_entrypoint_trig_pwr')dnl
define(`m4_gui_trig_pwr_provider',`state_handler_entrypoint')dnl
define(`m4_state_handler_entrypoint_collect_tm',`tm_collection_collect_tm')dnl
define(`m4_state_handler_entrypoint_collect_tm_provider',`tm_collection')dnl
define(`m4_state_handler_entrypoint_request_loc',`loc_provider_request_loc')dnl
define(`m4_state_handler_entrypoint_request_loc_provider',`loc_provider')dnl
define(`m4_state_handler_entrypoint_request_tc',`tc_provider_request_tc')dnl
define(`m4_state_handler_entrypoint_request_tc_provider',`tc_provider')dnl
define(`m4_state_handler_entrypoint_send_tm_aoi',`gui_send_tm_aoi')dnl
define(`m4_state_handler_entrypoint_send_tm_aoi_provider',`gui')dnl
define(`m4_state_handler_entrypoint_send_tm_mcp',`gui_send_tm_mcp')dnl
define(`m4_state_handler_entrypoint_send_tm_mcp_provider',`gui')dnl
define(`m4_state_handler_entrypoint_validate_mc_vs_tm',`tc_validation_validate_mc_vs_tm')dnl
define(`m4_state_handler_entrypoint_validate_mc_vs_tm_provider',`tc_validation')dnl
define(`m4_tm_collection_request_tm',`tm_provider_request_tm')dnl
define(`m4_tm_collection_request_tm_provider',`tm_provider')dnl
define(`m4_env_poll_aoi',`state_handler_entrypoint_poll_aoi')dnl
define(`m4_env_poll_aoi_provider',`state_handler_entrypoint')dnl
define(`m4_env_poll_mcp',`state_handler_entrypoint_poll_mcp')dnl
define(`m4_env_poll_mcp_provider',`state_handler_entrypoint')dnl
define(`m4_env_toggle_pwr',`state_handler_entrypoint_toggle_pwr')dnl
define(`m4_env_toggle_pwr_provider',`state_handler_entrypoint')dnl
divert(1)dnl
system taste;
/*
 *
 * Data View
 *
 */
include(dataview.if)

type math = abstract
    integer abs(integer);
    real abs(real);
    integer fix(real);
    real power(real, real);
    integer Shift_Left(integer, integer);
    integer Shift_Right(integer, integer);
    integer ceil(real);
    integer floor(real);
    real float(integer);
    integer round(real);
    real sin(real);
    real cos(real);
    integer trunc(real);
endabstract;

type enum_functions = abstract
undivert(7)
endabstract;


divert(20)
m4_sporadic_itf_gui_handler(
    gui,
    send_tm_aoi,
    `Location_Fix_Packet',
)

m4_sporadic_itf_gui_handler(
    gui,
    send_tm_mcp,
    `Mode_Change_Packet',
)


m4_sporadic_itf_gui_provider(
    gui,
    trig_aoi,
    ,
)

m4_sporadic_itf_gui_provider(
    gui,
    trig_mcp,
    ,
)

m4_sporadic_itf_gui_provider(
    gui,
    trig_pwr,
    ,
)


m4_gui_handler(gui)

m4_c_function(loc_provider,(request_loc,(lfp),(Location_Fix_Packet),(PARAM_OUT), 0),

)

m4_cyclic_itf_handler(
    state_handler_entrypoint,
    poll_aoi,
     10000,
     1)

m4_cyclic_itf_handler(
    state_handler_entrypoint,
    poll_mcp,
     5000,
     1)

m4_cyclic_itf_handler(
    state_handler_entrypoint,
    toggle_pwr,
     30000,
     1)

m4_sporadic_itf_handler(
    state_handler_entrypoint,
    trig_aoi,
    ,
     0,
     2)

m4_sporadic_itf_handler(
    state_handler_entrypoint,
    trig_mcp,
    ,
     0,
     2)

m4_sporadic_itf_handler(
    state_handler_entrypoint,
    trig_pwr,
    ,
     0,
     2)









include(state_handler_entrypoint.if)

m4_c_function(tc_provider,(request_tc,(mcp),(Mode_Change_Packet),(PARAM_OUT), 0),

)

m4_c_function(tc_validation,(validate_mc_vs_tm,(),(),(), 0),

)

m4_c_function(tm_collection,(collect_tm,(),(),(), 0),

)

m4_c_function(tm_provider,(request_tm,(temp, depl_d, depl_a),(Temperature_Generic, Deployment_Digital, Deployment_Analogue),(PARAM_OUT, PARAM_OUT, PARAM_OUT), 0),

)



divert(1)
type assign = abstract
undivert(5)
endabstract;

/*
 *
 * Interface View
 *
 */
signal set_timer(integer);
signal reset_timer();

undivert(10)

undivert(20)

endsystem;

priorityrules
undivert(30)
endpriorityrules;
