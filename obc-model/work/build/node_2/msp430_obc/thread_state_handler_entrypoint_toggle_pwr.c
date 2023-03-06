#include "thread_state_handler_entrypoint_toggle_pwr.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t state_handler_entrypoint_toggle_pwr_Global_Queue;

void prv_state_handler_entrypoint_toggle_pwr_Timer_Callback(TimerHandle_t timer)
{
    struct Request request;
    request.m_length = 0;
    xQueueSend(state_handler_entrypoint_toggle_pwr_Global_Queue, &request, 0);
}

__attribute__ ((persistent)) StaticTimer_t prv_state_handler_entrypoint_toggle_pwr_Timer_Buffer = {0};
__attribute__ ((persistent)) TimerHandle_t prv_state_handler_entrypoint_toggle_pwr_Timer = {0};

void prv_state_handler_entrypoint_toggle_pwr_Task(void* prParameters)
{
    extern QueueHandle_t state_handler_entrypoint_toggle_pwr_Global_Queue;
    TickType_t period = pdMS_TO_TICKS( 30000);
    prv_state_handler_entrypoint_toggle_pwr_Timer = xTimerCreateStatic("state_handler_entrypoint_toggle_pwr_Timer",
                                                         period,
                                                         pdTRUE,
                                                         NULL,
                                                         &prv_state_handler_entrypoint_toggle_pwr_Timer_Callback,
                                                         &prv_state_handler_entrypoint_toggle_pwr_Timer_Buffer);
    xTimerStart(prv_state_handler_entrypoint_toggle_pwr_Timer, portMAX_DELAY);

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(state_handler_entrypoint_toggle_pwr_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_state_handler_entrypoint_toggle_pwr((const char*)request.m_data, request.m_length);
        }
    }
}
