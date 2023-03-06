//  Provided interface "poll_aoi"
void state_handler_entrypoint_PI_poll_aoi();
//  Provided interface "poll_mcp"
void state_handler_entrypoint_PI_poll_mcp();
//  Provided interface "toggle_pwr"
void state_handler_entrypoint_PI_toggle_pwr();
//  Provided interface "trig_aoi"
void state_handler_entrypoint_PI_trig_aoi();
//  Provided interface "trig_mcp"
void state_handler_entrypoint_PI_trig_mcp();
//  Provided interface "trig_pwr"
void state_handler_entrypoint_PI_trig_pwr();
//  Output signal "send_tm_aoi
void state_handler_entrypoint_RI_send_tm_aoi(asn1SccLocation_Fix_Packet * lfp);
//  Output signal "send_tm_mcp
void state_handler_entrypoint_RI_send_tm_mcp(asn1SccMode_Change_Packet * mcp);
//  Sync required interface "collect_tm
void state_handler_entrypoint_RI_collect_tm();
//  Sync required interface "request_loc
void state_handler_entrypoint_RI_request_loc(asn1SccLocation_Fix_Packet * Lfp);
//  Sync required interface "request_tc
void state_handler_entrypoint_RI_request_tc(asn1SccMode_Change_Packet * Mcp);
//  Sync required interface "validate_mc_vs_tm
void state_handler_entrypoint_RI_validate_mc_vs_tm();