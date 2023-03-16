#include "thread_led_blinker_trigger_blink.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t led_blinker_trigger_blink_Global_Queue;

void prv_led_blinker_trigger_blink_Timer_Callback(TimerHandle_t timer)
{
    struct Request request;
    request.m_length = 0;
    xQueueSend(led_blinker_trigger_blink_Global_Queue, &request, 0);
}

__attribute__ ((persistent)) StaticTimer_t prv_led_blinker_trigger_blink_Timer_Buffer = {0};
__attribute__ ((persistent)) TimerHandle_t prv_led_blinker_trigger_blink_Timer = {0};

void prv_led_blinker_trigger_blink_Task(void* prParameters)
{
    extern QueueHandle_t led_blinker_trigger_blink_Global_Queue;
    TickType_t period = pdMS_TO_TICKS( 500);
    prv_led_blinker_trigger_blink_Timer = xTimerCreateStatic("led_blinker_trigger_blink_Timer",
                                                         period,
                                                         pdTRUE,
                                                         NULL,
                                                         &prv_led_blinker_trigger_blink_Timer_Callback,
                                                         &prv_led_blinker_trigger_blink_Timer_Buffer);
    xTimerStart(prv_led_blinker_trigger_blink_Timer, portMAX_DELAY);

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(led_blinker_trigger_blink_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_led_blinker_trigger_blink((const char*)request.m_data, request.m_length);
        }
    }
}
