/* Header file for function gui
 * Generated by TASTE on 2022-12-28 10:47:29
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void gui_startup(void);

/* Provided interfaces */
void gui_PI_Poll( void );


void gui_PI_send_tm_aoi( const asn1SccLocation_Fix_Packet * );


void gui_PI_send_tm_mcp( const asn1SccMode_Change_Packet * );

/* Required interfaces */
extern void gui_RI_trig_aoi( void );


extern void gui_RI_trig_mcp( void );


extern void gui_RI_trig_pwr( void );


#ifdef __cplusplus
}
#endif

