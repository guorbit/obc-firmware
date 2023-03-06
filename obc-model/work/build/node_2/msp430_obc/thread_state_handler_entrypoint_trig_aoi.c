#include "thread_state_handler_entrypoint_trig_aoi.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t state_handler_entrypoint_trig_aoi_Global_Queue;

void prv_state_handler_entrypoint_trig_aoi_Task(void* prParameters)
{
    extern QueueHandle_t state_handler_entrypoint_trig_aoi_Global_Queue;

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(state_handler_entrypoint_trig_aoi_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_state_handler_entrypoint_trig_aoi((const char*)request.m_data, request.m_length);
        }
    }
}
