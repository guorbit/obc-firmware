#include "thread_blinker_blink_trigger.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t blinker_blink_trigger_Global_Queue;

void prv_blinker_blink_trigger_Timer_Callback(TimerHandle_t timer)
{
    struct Request request;
    request.m_length = 0;
    xQueueSend(blinker_blink_trigger_Global_Queue, &request, 0);
}

__attribute__ ((persistent)) StaticTimer_t prv_blinker_blink_trigger_Timer_Buffer = {0};
__attribute__ ((persistent)) TimerHandle_t prv_blinker_blink_trigger_Timer = {0};

void prv_blinker_blink_trigger_Task(void* prParameters)
{
    extern QueueHandle_t blinker_blink_trigger_Global_Queue;
    TickType_t period = pdMS_TO_TICKS( 2000);
    prv_blinker_blink_trigger_Timer = xTimerCreateStatic("blinker_blink_trigger_Timer",
                                                         period,
                                                         pdTRUE,
                                                         NULL,
                                                         &prv_blinker_blink_trigger_Timer_Callback,
                                                         &prv_blinker_blink_trigger_Timer_Buffer);
    xTimerStart(prv_blinker_blink_trigger_Timer, portMAX_DELAY);

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(blinker_blink_trigger_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_blinker_blink_trigger((const char*)request.m_data, request.m_length);
        }
    }
}
