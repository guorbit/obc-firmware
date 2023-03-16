#include "thread_hal_blink_led.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t hal_blink_led_Global_Queue;

void prv_hal_blink_led_Timer_Callback(TimerHandle_t timer)
{
    struct Request request;
    request.m_length = 0;
    xQueueSend(hal_blink_led_Global_Queue, &request, 0);
}

__attribute__ ((persistent)) StaticTimer_t prv_hal_blink_led_Timer_Buffer = {0};
__attribute__ ((persistent)) TimerHandle_t prv_hal_blink_led_Timer = {0};

void prv_hal_blink_led_Task(void* prParameters)
{
    extern QueueHandle_t hal_blink_led_Global_Queue;
    TickType_t period = pdMS_TO_TICKS( 2000);
    prv_hal_blink_led_Timer = xTimerCreateStatic("hal_blink_led_Timer",
                                                         period,
                                                         pdTRUE,
                                                         NULL,
                                                         &prv_hal_blink_led_Timer_Callback,
                                                         &prv_hal_blink_led_Timer_Buffer);
    xTimerStart(prv_hal_blink_led_Timer, portMAX_DELAY);

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(hal_blink_led_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_hal_blink_led((const char*)request.m_data, request.m_length);
        }
    }
}
