#ifndef __OCARINA_GENERATED_ACTIVITY_H_
#define __OCARINA_GENERATED_ACTIVITY_H_ 
#include <request.h>
/**************************************************** */

/*  This file was automatically generated by Ocarina  */

/*  Working Copy from r36f4e31c */

/*  Do NOT hand-modify this file, as your             */

/*  changes will be lost when you re-run Ocarina      */

/**************************************************** */

void gui_poll_deliver 
    (__po_hi_request_t* request);

void* gui_poll_job (void);

void gui_send_tm_aoi_deliver 
    (__po_hi_request_t* request);

void* gui_send_tm_aoi_job (void);

void gui_send_tm_mcp_deliver 
    (__po_hi_request_t* request);

void* gui_send_tm_mcp_job (void);

void state_handler_entrypoint_poll_aoi_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_poll_aoi_job (void);

void state_handler_entrypoint_poll_mcp_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_poll_mcp_job (void);

void state_handler_entrypoint_toggle_pwr_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_toggle_pwr_job (void);

void state_handler_entrypoint_trig_aoi_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_trig_aoi_job (void);

void state_handler_entrypoint_trig_mcp_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_trig_mcp_job (void);

void state_handler_entrypoint_trig_pwr_deliver 
    (__po_hi_request_t* request);

void* state_handler_entrypoint_trig_pwr_job (void);

void __po_hi_main_deliver 
    (__po_hi_request_t* request);

#endif
