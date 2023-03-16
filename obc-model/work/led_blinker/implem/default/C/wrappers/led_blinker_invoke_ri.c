// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include "dataview-uniq.h"

extern unsigned led_blinker_initialized;

void led_blinker_RI_led_blink(void);
void led_blinker_RI_led_blink(void)
{


   // Send the message via the middleware API
   extern void vm_led_blinker_led_blink(void);
   vm_led_blinker_led_blink();

}

