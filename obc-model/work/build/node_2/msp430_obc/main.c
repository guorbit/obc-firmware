/* File generated by kazoo for TASTE - do not edit */
#include <msp430.h>

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "msp430_obc_interface.h"
#include "transport.h"

#include "drivers/msp430_eusci_a_serial_minimal/msp430_eusci_a_serial_minimal.h"

#include "thread_hal_blink_led.h"
#include "thread_state_handler_entrypoint_poll_aoi.h"
#include "thread_state_handler_entrypoint_poll_mcp.h"
#include "thread_state_handler_entrypoint_toggle_pwr.h"
#include "thread_state_handler_entrypoint_trig_aoi.h"
#include "thread_state_handler_entrypoint_trig_mcp.h"
#include "thread_state_handler_entrypoint_trig_pwr.h"

extern void init_hal(void);
extern void init_state_handler_entrypoint(void);
extern void init_loc_provider(void);
extern void init_tm_collection(void);
extern void init_tc_provider(void);

// function to setup hardware
static void prvSetupHardware()
{
    // stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    PM5CTL0 &= ~LOCKLPM5;

    // Unlock clock registers
    CSCTL0_H = CSKEY >> 8;

    // Set DCO to 8MHz
    CSCTL1 = DCOFSEL_3 | DCORSEL;

    // select LFXTCLK for ACLK
    // select DCO for SMCLK
    // select DCO for MCLK
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;

    // Set all dividers
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;

    // Lock clock registers
    CSCTL0_H = 0;

    // initialize devices
    msp430_eusci_a_serial_minimal_init();
}

// stack overflow handler
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void) pcTaskName;
    (void) pxTask;

    /* Run time stack overflow checking is performed if
     configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
     function is called if a stack overflow is detected.
     See http://www.freertos.org/Stacks-and-stack-overflow-checking.html */

    /* Force an assert. */
    configASSERT(( volatile void * ) NULL);
}

// MSP-430 timers setup
void vApplicationSetupTimerInterrupt(void)
{
    const unsigned short usACLK_Frequency_Hz = 32768;

    /* Ensure the timer is stopped. */
    TA0CTL = 0;

    /* Run the timer from the ACLK. */
    TA0CTL = TASSEL_1;

    /* Clear everything to start with. */
    TA0CTL |= TACLR;

    /* Set the compare match value according to the tick rate we want. */
    TA0CCR0 = usACLK_Frequency_Hz / configTICK_RATE_HZ;

    /* Enable the interrupts. */
    TA0CCTL0 = CCIE;

    /* Start up clean. */
    TA0CTL |= TACLR;

    /* Up mode. */
    TA0CTL |= MC_1;
}

__attribute__ ((persistent)) StaticTask_t xIdleTaskTCB = {0};
__attribute__ ((persistent)) StackType_t xIdleTaskStack[configMINIMAL_STACK_SIZE] = {0};

void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskPCBBuffer,
                                   StackType_t** ppxIdleTaskStackBuffer,
                                   uint32_t* pulIdleTaskStackSize)
{

    *ppxIdleTaskPCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = xIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

__attribute__ ((persistent)) StaticTask_t xTimerTaskTCB = {0};
__attribute__ ((persistent)) StackType_t xTimerTaskStack[configMINIMAL_STACK_SIZE] = {0};

void vApplicationGetTimerTaskMemory(StaticTask_t** ppxTimerTaskPCBBuffer,
                                   StackType_t** ppxTimerTaskStackBuffer,
                                   uint32_t* pulTimerTaskStackSize)
{

    *ppxTimerTaskPCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = xTimerTaskStack;
    *pulTimerTaskStackSize = configMINIMAL_STACK_SIZE;
}

__attribute__ ((persistent)) SemaphoreHandle_t hal_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_hal_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t state_handler_entrypoint_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_state_handler_entrypoint_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t loc_provider_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_loc_provider_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t tm_collection_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_tm_collection_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t tc_provider_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_tc_provider_Semaphore_Buffer = {0};



__attribute__ ((persistent)) QueueHandle_t hal_blink_led_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_hal_blink_led_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_hal_blink_led_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_hal_blink_led_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_hal_blink_led_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_hal_blink_led()
{
    hal_blink_led_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_hal_blink_led_Queue_Buffer,
                                                      &prv_hal_blink_led_Static_Queue);

    xTaskCreateStatic(prv_hal_blink_led_Task,
                "hal_blink_led",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_hal_blink_led_Stack,
                &prv_hal_blink_led_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_poll_aoi_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_poll_aoi_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_poll_aoi_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_poll_aoi_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_poll_aoi_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_poll_aoi()
{
    state_handler_entrypoint_poll_aoi_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_poll_aoi_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_poll_aoi_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_poll_aoi_Task,
                "state_handler_entrypoint_poll_aoi",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_poll_aoi_Stack,
                &prv_state_handler_entrypoint_poll_aoi_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_poll_mcp_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_poll_mcp_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_poll_mcp_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_poll_mcp_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_poll_mcp_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_poll_mcp()
{
    state_handler_entrypoint_poll_mcp_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_poll_mcp_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_poll_mcp_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_poll_mcp_Task,
                "state_handler_entrypoint_poll_mcp",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_poll_mcp_Stack,
                &prv_state_handler_entrypoint_poll_mcp_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_toggle_pwr_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_toggle_pwr_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_toggle_pwr_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_toggle_pwr_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_toggle_pwr_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_toggle_pwr()
{
    state_handler_entrypoint_toggle_pwr_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_toggle_pwr_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_toggle_pwr_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_toggle_pwr_Task,
                "state_handler_entrypoint_toggle_pwr",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_toggle_pwr_Stack,
                &prv_state_handler_entrypoint_toggle_pwr_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_trig_aoi_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_trig_aoi_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_trig_aoi_Queue_Buffer[ 10 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_trig_aoi_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_trig_aoi_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_trig_aoi()
{
    state_handler_entrypoint_trig_aoi_Global_Queue = xQueueCreateStatic( 10,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_trig_aoi_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_trig_aoi_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_trig_aoi_Task,
                "state_handler_entrypoint_trig_aoi",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_trig_aoi_Stack,
                &prv_state_handler_entrypoint_trig_aoi_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_trig_mcp_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_trig_mcp_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_trig_mcp_Queue_Buffer[ 10 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_trig_mcp_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_trig_mcp_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_trig_mcp()
{
    state_handler_entrypoint_trig_mcp_Global_Queue = xQueueCreateStatic( 10,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_trig_mcp_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_trig_mcp_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_trig_mcp_Task,
                "state_handler_entrypoint_trig_mcp",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_trig_mcp_Stack,
                &prv_state_handler_entrypoint_trig_mcp_TCB);
}

__attribute__ ((persistent)) QueueHandle_t state_handler_entrypoint_trig_pwr_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_state_handler_entrypoint_trig_pwr_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_state_handler_entrypoint_trig_pwr_Queue_Buffer[ 10 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_state_handler_entrypoint_trig_pwr_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_state_handler_entrypoint_trig_pwr_Stack[ 1024 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_state_handler_entrypoint_trig_pwr()
{
    state_handler_entrypoint_trig_pwr_Global_Queue = xQueueCreateStatic( 10,
                                                      sizeof(struct Request),
                                                      prv_state_handler_entrypoint_trig_pwr_Queue_Buffer,
                                                      &prv_state_handler_entrypoint_trig_pwr_Static_Queue);

    xTaskCreateStatic(prv_state_handler_entrypoint_trig_pwr_Task,
                "state_handler_entrypoint_trig_pwr",
                 1024 / sizeof(StackType_t),
                NULL,
                 1,
                prv_state_handler_entrypoint_trig_pwr_Stack,
                &prv_state_handler_entrypoint_trig_pwr_TCB);
}

// the main function
int main(void)
{
    prvSetupHardware();

    hal_Semaphore = xSemaphoreCreateMutexStatic(&prv_hal_Semaphore_Buffer);
    init_hal();
    state_handler_entrypoint_Semaphore = xSemaphoreCreateMutexStatic(&prv_state_handler_entrypoint_Semaphore_Buffer);
    init_state_handler_entrypoint();
    loc_provider_Semaphore = xSemaphoreCreateMutexStatic(&prv_loc_provider_Semaphore_Buffer);
    init_loc_provider();
    tm_collection_Semaphore = xSemaphoreCreateMutexStatic(&prv_tm_collection_Semaphore_Buffer);
    init_tm_collection();
    tc_provider_Semaphore = xSemaphoreCreateMutexStatic(&prv_tc_provider_Semaphore_Buffer);
    init_tc_provider();

    Initialize_Thread_hal_blink_led();
    Initialize_Thread_state_handler_entrypoint_poll_aoi();
    Initialize_Thread_state_handler_entrypoint_poll_mcp();
    Initialize_Thread_state_handler_entrypoint_toggle_pwr();
    Initialize_Thread_state_handler_entrypoint_trig_aoi();
    Initialize_Thread_state_handler_entrypoint_trig_mcp();
    Initialize_Thread_state_handler_entrypoint_trig_pwr();

    vTaskStartScheduler();

    for(;;);
}


