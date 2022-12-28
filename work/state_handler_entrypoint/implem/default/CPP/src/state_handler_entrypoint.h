/* Header file for function state_handler_entrypoint
 * Generated by TASTE on 2022-12-28 10:33:55
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void state_handler_entrypoint_startup(void);

/* Provided interfaces */
void state_handler_entrypoint_PI_poll_aoi( );


void state_handler_entrypoint_PI_poll_mcp( );


void state_handler_entrypoint_PI_toggle_pwr( );


void state_handler_entrypoint_PI_trig_aoi( );


void state_handler_entrypoint_PI_trig_mcp( );


void state_handler_entrypoint_PI_trig_pwr( );

/* Required interfaces */
extern void state_handler_entrypoint_RI_collect_tm( );


extern void state_handler_entrypoint_RI_request_loc( asn1SccLocation_Fix_Packet * );


extern void state_handler_entrypoint_RI_request_tc( asn1SccMode_Change_Packet * );


extern void state_handler_entrypoint_RI_send_tm_aoi( const asn1SccLocation_Fix_Packet * );


extern void state_handler_entrypoint_RI_send_tm_mcp( const asn1SccMode_Change_Packet * );


extern void state_handler_entrypoint_RI_validate_mc_vs_tm( );


#ifdef __cplusplus
}
#endif

