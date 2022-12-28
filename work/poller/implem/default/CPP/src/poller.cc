// Body file for function poller
// Generated by TASTE on 2022-12-02 00:28:19
// You can edit this file, it will not be overwritten
// Provided interfaces : poll_aoi, poll_mcp
// Required interfaces : poll_aoi_trig, poll_mcp_trig
// User-defined properties for this function:
//   |_ Taste::Startup_Priority = 1
// Timers              : 

#include "poller.h"
#include "poller_state.h"
#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
poller_state ctxt_poller;


void poller_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   std::cout << "[poller] Initialising C++ implementation" << std::endl;
}


void poller_PI_poll_aoi(void)
{
   // Write your code here
    poller_RI_poll_aoi_trig();
}


void poller_PI_poll_mcp(void)
{
   // Write your code here
    poller_RI_poll_mcp_trig();
}


void poller_PI_toggle_pwr(void)
{
   // Write your code here
    poller_RI_toggle_pwr_trig();
}

