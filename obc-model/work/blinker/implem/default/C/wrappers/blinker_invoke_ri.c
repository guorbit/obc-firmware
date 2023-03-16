// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include "dataview-uniq.h"

extern unsigned blinker_initialized;

void blinker_RI_toggle_led(void);
void blinker_RI_toggle_led(void)
{


   // Send the message via the middleware API
   extern void vm_blinker_toggle_led(void);
   vm_blinker_toggle_led();

}

