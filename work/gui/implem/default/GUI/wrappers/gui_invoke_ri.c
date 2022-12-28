// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#include "dataview-uniq.h"

extern unsigned gui_initialized;

void gui_RI_trig_aoi(void);
void gui_RI_trig_aoi(void)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to state_handler_entrypoint (corresponding PI: trig_aoi)
      printf ("INNER_RI: gui,state_handler_entrypoint,trig_aoi,trig_aoi,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_gui_trig_aoi(void);
   vm_gui_trig_aoi();

}



void gui_RI_trig_mcp(void);
void gui_RI_trig_mcp(void)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to state_handler_entrypoint (corresponding PI: trig_mcp)
      printf ("INNER_RI: gui,state_handler_entrypoint,trig_mcp,trig_mcp,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_gui_trig_mcp(void);
   vm_gui_trig_mcp();

}



void gui_RI_trig_pwr(void);
void gui_RI_trig_pwr(void)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to state_handler_entrypoint (corresponding PI: trig_pwr)
      printf ("INNER_RI: gui,state_handler_entrypoint,trig_pwr,trig_pwr,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_gui_trig_pwr(void);
   vm_gui_trig_pwr();

}

