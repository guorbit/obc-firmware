#include <stdio.h>
#include "dataview-uniq.h"
#include "State_Handler_Entrypoint.h"
typedef enum {sleep, wait} states_t;
typedef struct
{
   states_t state;
   asn1SccCounterK k;
   asn1SccCounterK s;
   asn1SccCounterK w;
   asn1SccCounterK k_max;
   asn1SccCounterK s_max;
   asn1SccCounterK w_max;
   asn1SccMode_Change_Packet mcp;
   asn1SccLocation_Fix_Packet lfp;
} context_t;
__attribute__ ((persistent)) context_t state_handler_entrypoint_context = {0};
void runTransitionState_Handler_Entrypoint(int Id);
void CInitState_Handler_Entrypoint()
{
   runTransitionState_Handler_Entrypoint(0);
}
void state_handler_entrypoint_PI_poll_aoi()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(1);
         break;
      }
      default:
      {
         break;
      }
   }
}

void state_handler_entrypoint_PI_poll_mcp()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(2);
         break;
      }
      default:
      {
         break;
      }
   }
}

void state_handler_entrypoint_PI_toggle_pwr()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         runTransitionState_Handler_Entrypoint(6);
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(3);
         break;
      }
      default:
      {
         break;
      }
   }
}

void state_handler_entrypoint_PI_trig_aoi()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(1);
         break;
      }
      default:
      {
         break;
      }
   }
}

void state_handler_entrypoint_PI_trig_mcp()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(2);
         break;
      }
      default:
      {
         break;
      }
   }
}

void state_handler_entrypoint_PI_trig_pwr()
{
   switch(state_handler_entrypoint_context.state)
   {
      case sleep:
      {
         runTransitionState_Handler_Entrypoint(5);
         break;
      }
      case wait:
      {
         runTransitionState_Handler_Entrypoint(4);
         break;
      }
      default:
      {
         break;
      }
   }
}

//  Required interface "send_tm_aoi"
#define send_tm_aoi state_handler_entrypoint_RI_send_tm_aoi
//  Required interface "send_tm_mcp"
#define send_tm_mcp state_handler_entrypoint_RI_send_tm_mcp
#define collect_tm state_handler_entrypoint_RI_collect_tm
#define request_loc state_handler_entrypoint_RI_request_loc
#define request_tc state_handler_entrypoint_RI_request_tc
void runTransitionState_Handler_Entrypoint(int Id)
{
   int trId = Id;
   while (trId != -1)
   {
      switch(trId)
      {
         case 0:
         {
            // writeln("[state_handler_entrypoint] Initialising SDL implementation") (15,13)
            printf("[state_handler_entrypoint] Initialising SDL implementation");
            printf("\n");
            // k_max := 999 (17,13)
            state_handler_entrypoint_context.k_max = 999;
            // s_max := 3 (19,13)
            state_handler_entrypoint_context.s_max = 3;
            // w_max := 1 (21,13)
            state_handler_entrypoint_context.w_max = 1;
            // NEXT_STATE Wait (23,18) at 522, 277
            trId = -1;
            state_handler_entrypoint_context.state = wait;
            goto next_transition;
            break;
         }
         case 1:
         {
            // request_loc(lfp) (29,17)
            request_loc(&state_handler_entrypoint_context.lfp);
            // writeln("[state_handler_entrypoint] [poll_aoi] printout:") (31,17)
            printf("[state_handler_entrypoint] [poll_aoi] printout:");
            printf("\n");
            // writeln("    k: ", k) (33,17)
            printf("    k: ");
            if((int)(state_handler_entrypoint_context.k) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.k);
            printf("\n");
            // writeln("    t: ", lfp.t) (35,17)
            printf("    t: ");
            if((int)(state_handler_entrypoint_context.lfp.t) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.lfp.t);
            printf("\n");
            // writeln("    lat: ", lfp.lat) (37,17)
            printf("    lat: ");
            printf(" %lf", state_handler_entrypoint_context.lfp.lat);
            printf("\n");
            // writeln("    lon: ", lfp.lon) (39,17)
            printf("    lon: ");
            printf(" %lf", state_handler_entrypoint_context.lfp.lon);
            printf("\n");
            // writeln("") (41,17)
            printf("");
            printf("\n");
            // send_tm_aoi(lfp) (43,19)
            send_tm_aoi(&state_handler_entrypoint_context.lfp);
            // k := (k+1) mod (k_max+1) (45,17)
            state_handler_entrypoint_context.k = ((state_handler_entrypoint_context.k + 1) % (state_handler_entrypoint_context.k_max + 1));
            // NEXT_STATE Wait (47,22) at 1158, 786
            trId = -1;
            state_handler_entrypoint_context.state = wait;
            goto next_transition;
            break;
         }
         case 2:
         {
            // request_tc(mcp) (51,17)
            request_tc(&state_handler_entrypoint_context.mcp);
            // writeln("[state_handler_entrypoint] [poll_mcp] printout:") (53,17)
            printf("[state_handler_entrypoint] [poll_mcp] printout:");
            printf("\n");
            // writeln("    k: ", k) (55,17)
            printf("    k: ");
            if((int)(state_handler_entrypoint_context.k) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.k);
            printf("\n");
            // writeln("    target-addr: ", mcp.target_addr) (57,17)
            printf("    target-addr: ");
            if((int)(state_handler_entrypoint_context.mcp.target_addr) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.mcp.target_addr);
            printf("\n");
            // writeln("    target-mode: ", mcp.target_mode) (59,17)
            printf("    target-mode: ");
            if((int)(state_handler_entrypoint_context.mcp.target_mode) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.mcp.target_mode);
            printf("\n");
            // writeln("    ttl-ms:", mcp.ttl_ms) (61,17)
            printf("    ttl-ms:");
            if((int)(state_handler_entrypoint_context.mcp.ttl_ms) >= 0) printf(" ");
            printf("%d", state_handler_entrypoint_context.mcp.ttl_ms);
            printf("\n");
            // writeln("") (63,17)
            printf("");
            printf("\n");
            // send_tm_mcp(mcp) (65,19)
            send_tm_mcp(&state_handler_entrypoint_context.mcp);
            // k := (k+1) mod (k_max+1) (67,17)
            state_handler_entrypoint_context.k = ((state_handler_entrypoint_context.k + 1) % (state_handler_entrypoint_context.k_max + 1));
            // NEXT_STATE Wait (69,22) at 755, 786
            trId = -1;
            state_handler_entrypoint_context.state = wait;
            goto next_transition;
            break;
         }
         case 3:
         {
            // w := (w+1) mod (w_max+1) (76,17)
            state_handler_entrypoint_context.w = ((state_handler_entrypoint_context.w + 1) % (state_handler_entrypoint_context.w_max + 1));
            // DECISION w = w_max (78,23)
            // ANSWER false (80,17)
            if(((state_handler_entrypoint_context.w == state_handler_entrypoint_context.w_max)) == false)
            {
               ;
            }
            // ANSWER true (82,17)
            else if(((state_handler_entrypoint_context.w == state_handler_entrypoint_context.w_max)) == true)
            {
               // JOIN sleep (None,None) at None, None
               goto sleep;
            }
            // NEXT_STATE Wait (93,22) at 1634, 713
            trId = -1;
            state_handler_entrypoint_context.state = wait;
            goto next_transition;
            break;
         }
         case 4:
         {
            // JOIN sleep (97,17) at 1834, 340
            goto sleep;
            break;
         }
         case 5:
         {
            // JOIN wake (104,17) at 2310, 340
            goto wake;
            break;
         }
         case 6:
         {
            // s := (s+1) mod (s_max+1) (108,17)
            state_handler_entrypoint_context.s = ((state_handler_entrypoint_context.s + 1) % (state_handler_entrypoint_context.s_max + 1));
            // DECISION s = s_max (110,23)
            // ANSWER false (112,17)
            if(((state_handler_entrypoint_context.s == state_handler_entrypoint_context.s_max)) == false)
            {
               // NEXT_STATE Sleep (114,30) at 2212, 508
               trId = -1;
               state_handler_entrypoint_context.state = sleep;
               goto next_transition;
            }
            // ANSWER true (116,17)
            else if(((state_handler_entrypoint_context.s == state_handler_entrypoint_context.s_max)) == true)
            {
               // JOIN wake (None,None) at None, None
               goto wake;
            }
            // NEXT_STATE Wait (125,22) at 2100, 714
            trId = -1;
            state_handler_entrypoint_context.state = wait;
            goto next_transition;
            break;
         }
         default:
         {
            break;
         }
      }
      goto next_transition;
      // CONNECTION sleep (84,20)
      sleep:
      // writeln("[state_handler_entrypoint] going to sleep") (86,25)
      printf("[state_handler_entrypoint] going to sleep");
      printf("\n");
      // writeln("") (88,25)
      printf("");
      printf("\n");
      // NEXT_STATE Sleep (90,30) at 1522, 648
      trId = -1;
      state_handler_entrypoint_context.state = sleep;
      goto next_transition;
      // CONNECTION wake (118,20)
      wake:
      // writeln("[state_handler_entrypoint] waking up") (120,25)
      printf("[state_handler_entrypoint] waking up");
      printf("\n");
      // writeln("") (122,25)
      printf("");
      printf("\n");
      // NEXT_STATE Wait (125,22) at 2100, 714
      trId = -1;
      state_handler_entrypoint_context.state = wait;
      goto next_transition;
      next_transition:
      ;
   }
}


char *state_handler_entrypoint_state(void)
{
     return "Not_supported_in_C__Use_the_Ada_backend";
}