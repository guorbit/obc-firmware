#include "thread_hal_toggle_led.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430_obc_interface.h"

extern QueueHandle_t hal_toggle_led_Global_Queue;

void prv_hal_toggle_led_Task(void* prParameters)
{
    extern QueueHandle_t hal_toggle_led_Global_Queue;

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(hal_toggle_led_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_hal_toggle_led((const char*)request.m_data, request.m_length);
        }
    }
}
