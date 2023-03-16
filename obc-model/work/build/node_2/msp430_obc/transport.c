#include "transport.h"

#include <msp430.h>
#include <string.h>

// use header genrated by ocarina for port identyfication
#include <deployment.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

__attribute__ ((persistent)) static RemoteTransportFuncPtr remote_transport_func = NULL;
void register_remote_transport_func(RemoteTransportFuncPtr fn)
{
    remote_transport_func = fn;
}

extern QueueHandle_t state_handler_entrypoint_trig_aoi_Global_Queue;
extern QueueHandle_t state_handler_entrypoint_trig_mcp_Global_Queue;
extern QueueHandle_t state_handler_entrypoint_trig_pwr_Global_Queue;

void process_incomming_message(struct Message* msg)
{
    struct Request request;
    if(msg->m_length > 0)
    {
        memcpy(request.m_data, msg->m_data, msg->m_length);
        request.m_length = msg->m_length;
    }
    else
    {
        request.m_length = 0;
    }

    switch(msg->m_port)
    {
        case state_handler_entrypoint_trig_aoi_global_inport_trig_aoi:
            xQueueSend(state_handler_entrypoint_trig_aoi_Global_Queue,
                       &request,
                       0);

            break;
        case state_handler_entrypoint_trig_mcp_global_inport_trig_mcp:
            xQueueSend(state_handler_entrypoint_trig_mcp_Global_Queue,
                       &request,
                       0);

            break;
        case state_handler_entrypoint_trig_pwr_global_inport_trig_pwr:
            xQueueSend(state_handler_entrypoint_trig_pwr_Global_Queue,
                       &request,
                       0);

            break;
    }
}


void deliver_to_gui_send_tm_aoi(struct Request* task)
{
    if(remote_transport_func != NULL)
    {
        remote_transport_func(task->m_data,
                              task->m_length,
                              (uint32_t) gui_send_tm_aoi_global_inport_send_tm_aoi);
    }
}
void deliver_to_gui_send_tm_mcp(struct Request* task)
{
    if(remote_transport_func != NULL)
    {
        remote_transport_func(task->m_data,
                              task->m_length,
                              (uint32_t) gui_send_tm_mcp_global_inport_send_tm_mcp);
    }
}

void deliver_to_hal_blink_led(struct Request* task)
{
    extern QueueHandle_t hal_blink_led_Global_Queue;
	xQueueSend(hal_blink_led_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_poll_aoi(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_poll_aoi_Global_Queue;
	xQueueSend(state_handler_entrypoint_poll_aoi_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_poll_mcp(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_poll_mcp_Global_Queue;
	xQueueSend(state_handler_entrypoint_poll_mcp_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_toggle_pwr(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_toggle_pwr_Global_Queue;
	xQueueSend(state_handler_entrypoint_toggle_pwr_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_trig_aoi(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_trig_aoi_Global_Queue;
	xQueueSend(state_handler_entrypoint_trig_aoi_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_trig_mcp(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_trig_mcp_Global_Queue;
	xQueueSend(state_handler_entrypoint_trig_mcp_Global_Queue,
	           task,
			   0);

}
void deliver_to_state_handler_entrypoint_trig_pwr(struct Request* task)
{
    extern QueueHandle_t state_handler_entrypoint_trig_pwr_Global_Queue;
	xQueueSend(state_handler_entrypoint_trig_pwr_Global_Queue,
	           task,
			   0);

}

