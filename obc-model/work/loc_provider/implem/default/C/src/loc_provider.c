/* Body file for function loc_provider
 * Generated by TASTE on 2022-11-27 16:30:03
 * You can edit this file, it will not be overwritten
 * Provided interfaces : request_loc
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "loc_provider.h"
#include <stdio.h>

static asn1SccCounterK k;


void loc_provider_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   puts ("[loc_provider] Initialising C++ implementation");
}

void loc_provider_PI_request_loc
      (asn1SccLocation_Fix_Packet *OUT_lfp)

{
   // Write your code here

    OUT_lfp->t = k;
    OUT_lfp->lat = 45;
    OUT_lfp->lon = -10;

    k++;
}


