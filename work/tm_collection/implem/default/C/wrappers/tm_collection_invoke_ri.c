// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned tm_collection_initialized;

void tm_collection_RI_request_tm
      (asn1SccTemperature_Generic *OUT_temp,
       asn1SccDeployment_Digital  *OUT_depl_d,
       asn1SccDeployment_Analogue *OUT_depl_a);
void tm_collection_RI_request_tm
      (asn1SccTemperature_Generic *OUT_temp,
       asn1SccDeployment_Digital  *OUT_depl_d,
       asn1SccDeployment_Analogue *OUT_depl_a)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to tm_provider (corresponding PI: request_tm)
      printf ("INNER_RI: tm_collection,tm_provider,request_tm,request_tm,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_temp = 0;
   size_t      size_OUT_buf_depl_d = 0;
   size_t      size_OUT_buf_depl_a = 0;

   // Send the message via the middleware API
   extern void vm_tm_collection_request_tm
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_tm_collection_request_tm
     ((void *)OUT_temp, &size_OUT_buf_temp,
      (void *)OUT_depl_d, &size_OUT_buf_depl_d,
      (void *)OUT_depl_a, &size_OUT_buf_depl_a);


}

