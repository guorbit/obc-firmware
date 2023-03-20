/* Body file for function HAL
 * Generated by TASTE on 2023-03-18 10:06:35
 * You can edit this file, it will not be overwritten
 * Provided interfaces : blink_led
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "hal.h"

#include <stdio.h>
#include <string.h>

volatile bool LED_ON = false;

void hal_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   puts ("[HAL] Startup");
}

void hal_PI_blink_led( void )
{
    puts("blink");
}

void hal_PI_read_led( asn1SccT_Boolean *OUT_val )
{
    *OUT_val = LED_ON;
}

void hal_PI_set_led( const asn1SccT_Boolean *IN_val )
{
    LED_ON = *IN_val;
}

void hal_PI_toggle_led( const asn1SccDelay_ns *IN_on_time_ns )
{
    LED_ON = !LED_ON;
    for (int i=0; i<=(*IN_on_time_ns); i++)
    {}
    LED_ON = !LED_ON;
}
