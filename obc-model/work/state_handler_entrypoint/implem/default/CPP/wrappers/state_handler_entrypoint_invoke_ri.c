// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned state_handler_entrypoint_initialized;

void state_handler_entrypoint_RI_collect_tm(void);
void state_handler_entrypoint_RI_collect_tm(void)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to tm_collection (corresponding PI: collect_tm)
      printf ("INNER_RI: state_handler_entrypoint,tm_collection,collect_tm,collect_tm,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_collect_tm(void);
   vm_state_handler_entrypoint_collect_tm();

}



void state_handler_entrypoint_RI_request_loc
      (asn1SccLocation_Fix_Packet *OUT_lfp);
void state_handler_entrypoint_RI_request_loc
      (asn1SccLocation_Fix_Packet *OUT_lfp)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to loc_provider (corresponding PI: request_loc)
      printf ("INNER_RI: state_handler_entrypoint,loc_provider,request_loc,request_loc,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_lfp = 0;

   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_request_loc
     (void *, size_t *);

   vm_state_handler_entrypoint_request_loc
     ((void *)OUT_lfp, &size_OUT_buf_lfp);


}



void state_handler_entrypoint_RI_request_tc
      (asn1SccMode_Change_Packet *OUT_mcp);
void state_handler_entrypoint_RI_request_tc
      (asn1SccMode_Change_Packet *OUT_mcp)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to tc_provider (corresponding PI: request_tc)
      printf ("INNER_RI: state_handler_entrypoint,tc_provider,request_tc,request_tc,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_mcp = 0;

   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_request_tc
     (void *, size_t *);

   vm_state_handler_entrypoint_request_tc
     ((void *)OUT_mcp, &size_OUT_buf_mcp);


}



void state_handler_entrypoint_RI_send_tm_aoi
      (const asn1SccLocation_Fix_Packet *IN_lfp);
void state_handler_entrypoint_RI_send_tm_aoi
      (const asn1SccLocation_Fix_Packet *IN_lfp)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to gui (corresponding PI: send_tm_aoi)
      printf ("INNER_RI: state_handler_entrypoint,gui,send_tm_aoi,send_tm_aoi,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_send_tm_aoi
     (void *, size_t);

   vm_state_handler_entrypoint_send_tm_aoi
     ((void *)IN_lfp, sizeof(asn1SccLocation_Fix_Packet));


}



void state_handler_entrypoint_RI_send_tm_mcp
      (const asn1SccMode_Change_Packet *IN_mcp);
void state_handler_entrypoint_RI_send_tm_mcp
      (const asn1SccMode_Change_Packet *IN_mcp)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to gui (corresponding PI: send_tm_mcp)
      printf ("INNER_RI: state_handler_entrypoint,gui,send_tm_mcp,send_tm_mcp,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_send_tm_mcp
     (void *, size_t);

   vm_state_handler_entrypoint_send_tm_mcp
     ((void *)IN_mcp, sizeof(asn1SccMode_Change_Packet));


}



void state_handler_entrypoint_RI_validate_mc_vs_tm(void);
void state_handler_entrypoint_RI_validate_mc_vs_tm(void)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to tc_validation (corresponding PI: validate_mc_vs_tm)
      printf ("INNER_RI: state_handler_entrypoint,tc_validation,validate_mc_vs_tm,validate_mc_vs_tm,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_validate_mc_vs_tm(void);
   vm_state_handler_entrypoint_validate_mc_vs_tm();

}

