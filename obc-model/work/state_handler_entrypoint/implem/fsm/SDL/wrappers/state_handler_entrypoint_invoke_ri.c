// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned state_handler_entrypoint_initialized;

void state_handler_entrypoint_RI_collect_tm(void);
void state_handler_entrypoint_RI_collect_tm(void)
{


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_collect_tm(void);
   vm_state_handler_entrypoint_collect_tm();

}



void state_handler_entrypoint_RI_request_loc
      (asn1SccLocation_Fix_Packet *OUT_lfp);
void state_handler_entrypoint_RI_request_loc
      (asn1SccLocation_Fix_Packet *OUT_lfp)
{

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


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_send_tm_mcp
     (void *, size_t);

   vm_state_handler_entrypoint_send_tm_mcp
     ((void *)IN_mcp, sizeof(asn1SccMode_Change_Packet));


}



void state_handler_entrypoint_RI_validate_mc_vs_tm(void);
void state_handler_entrypoint_RI_validate_mc_vs_tm(void)
{


   // Send the message via the middleware API
   extern void vm_state_handler_entrypoint_validate_mc_vs_tm(void);
   vm_state_handler_entrypoint_validate_mc_vs_tm();

}

