/* Body file for function tc_provider
 * Generated by TASTE on 2022-11-27 16:30:03
 * You can edit this file, it will not be overwritten
 * Provided interfaces : request_tc
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "tc_provider.h"
//#include <stdio.h>

static asn1SccCounterK k;


void tc_provider_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[tc_provider] Startup");
}

void tc_provider_PI_request_tc
      (asn1SccMode_Change_Packet *OUT_mcp)

{
   // Write your code here
    OUT_mcp->target_addr = 0;
    OUT_mcp->target_mode = 0;
    OUT_mcp->ttl_ms = 1000;

    k++;
}


