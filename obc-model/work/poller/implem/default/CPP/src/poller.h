/* Header file for function poller
 * Generated by TASTE on 2022-12-02 00:33:28
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void poller_startup(void);

/* Provided interfaces */
void poller_PI_poll_aoi( );


void poller_PI_poll_mcp( );


void poller_PI_toggle_pwr( );

/* Required interfaces */
extern void poller_RI_poll_aoi_trig( );


extern void poller_RI_poll_mcp_trig( );


extern void poller_RI_toggle_pwr_trig( );


#ifdef __cplusplus
}
#endif

