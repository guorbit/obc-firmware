#include "dataview-uniq.h"
#include "Blinker.h"
typedef enum {wait} states_t;
typedef struct
{
   states_t state;
} context_t;
__attribute__ ((persistent)) context_t blinker_context = {0};
void runTransitionBlinker(int Id);
void CInitBlinker()
{
   runTransitionBlinker(0);
}
void blinker_PI_blink_trigger()
{
   switch(blinker_context.state)
   {
      case wait:
      {
         runTransitionBlinker(1);
         break;
      }
      default:
      {
         break;
      }
   }
}

//  Required interface "toggle_led"
#define toggle_led blinker_RI_toggle_led
void runTransitionBlinker(int Id)
{
   int trId = Id;
   while (trId != -1)
   {
      switch(trId)
      {
         case 0:
         {
            // NEXT_STATE Wait (6,18) at 320, 60
            trId = -1;
            blinker_context.state = wait;
            goto next_transition;
            break;
         }
         case 1:
         {
            // toggle_led (12,17)
            toggle_led();
            // NEXT_STATE Wait (14,22) at 450, 175
            trId = -1;
            blinker_context.state = wait;
            goto next_transition;
            break;
         }
         default:
         {
            break;
         }
      }
      next_transition:
      ;
   }
}


char *blinker_state(void)
{
     return "Not_supported_in_C__Use_the_Ada_backend";
}