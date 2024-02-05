// Autogenerated code (from TASTE/Kazoo) : DO NOT EDIT

#include "demo_timer_manager.h"

// When system_mode_manager_init_timer expires, this function is called:
extern void demo_timer_manager_RI_system_mode_manager_init_timer(void);

void demo_timer_manager_startup(void)
{
 // Timer start up (nothing to do)
}

void demo_timer_manager_PI_Tick(void)
{
   if (active == timers[system_mode_manager_init_timer].state && 0 == -- timers[system_mode_manager_init_timer].value) {
      demo_timer_manager_RI_system_mode_manager_init_timer();
      timers[system_mode_manager_init_timer].state = inactive;
   }

}

void demo_timer_manager_PI_SET_system_mode_manager_init_timer(asn1SccT_UInt32 *val)
{
   /* Timer value must be multiple of 10 ms */
   assert (0 == (*val % 10));
   timers[system_mode_manager_init_timer].state = active;
   timers[system_mode_manager_init_timer].value = *val / 10;
}

void demo_timer_manager_PI_RESET_system_mode_manager_init_timer(void)
{
   timers[system_mode_manager_init_timer].state = inactive;
}


