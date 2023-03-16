#ifndef TRANSPORT_H_INCLUDED
#define TRANSPORT_H_INCLUDED

#include <stdint.h>

#include "dataview-uniq.h"

// struct used to calculate request size
struct MSPAllParameters
{
    union
    {
        // for all provided sporadic and cyclic interfaces
        








        // for all required sporadic interfaces
        

char state_handler_entrypoint_send_tm_aoi_lfp[sizeof (asn1SccLocation_Fix_Packet)];
char state_handler_entrypoint_send_tm_mcp_mcp[sizeof (asn1SccMode_Change_Packet)];
        char dummy_union_field;
    } all_types;
};

// MSP430_BUFFER_SIZE should be even number
#define MSP430_BUFFER_SIZE (((sizeof(struct MSPAllParameters) + 1) / 2) * 2)

struct Request
{
	uint32_t m_length;
    uint8_t m_data[MSP430_BUFFER_SIZE];

};


struct Message
{
    uint32_t m_port;
    uint32_t m_length;
    uint8_t m_data[MSP430_BUFFER_SIZE];

};

void process_incomming_message(struct Message* msg);

typedef void (*RemoteTransportFuncPtr)(uint8_t* data, uint32_t length, uint32_t port);
void register_remote_transport_func(RemoteTransportFuncPtr fn);

void deliver_to_gui_send_tm_aoi(struct Request* task);
void deliver_to_gui_send_tm_mcp(struct Request* task);


void deliver_to_hal_blink_led(struct Request* task);
void deliver_to_state_handler_entrypoint_poll_aoi(struct Request* task);
void deliver_to_state_handler_entrypoint_poll_mcp(struct Request* task);
void deliver_to_state_handler_entrypoint_toggle_pwr(struct Request* task);
void deliver_to_state_handler_entrypoint_trig_aoi(struct Request* task);
void deliver_to_state_handler_entrypoint_trig_mcp(struct Request* task);
void deliver_to_state_handler_entrypoint_trig_pwr(struct Request* task);

#endif
