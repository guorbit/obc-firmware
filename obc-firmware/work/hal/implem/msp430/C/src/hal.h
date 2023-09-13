/* Header file for function HAL
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void hal_startup(void);

/* Provided interfaces */
void hal_PI_blink_led( void );


void hal_PI_send_camera_capture_image_pulse( void );


void hal_PI_send_camera_idle_signal( void );


void hal_PI_send_camera_toggle_usb_pulse( void );


void hal_PI_set_led( const asn1SccT_Boolean * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif
