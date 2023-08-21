/* Body file for function HAL
 * Generated by TASTE on 2023-03-10 23:20:06
 * You can edit this file, it will not be overwritten
 * Provided interfaces : get_temperature, led_blink
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "hal.h"

#include <msp430.h>
#include <FreeRTOS.h>
#include <semphr.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msp430_uart.h"

#define CMD_CODE_LENGTH 2
#define PAYLOAD_ID_LENGTH 6
#define FIELD_LIST_LENGTH 12
#define LORA_UPLING_CODE_LENGTH 0
#define APRS_CALLSIGN_LENGTH 0

bool P4_6_LED_ON = false;

typedef struct cmdQueueNode
{
    struct cmdQueueNode* next;
    unsigned char* cmdData; // cmd code always exactly of size 2
    uint8_t cmdDataSize;
} cmdQueueNode;

typedef struct cmdQueue
{
    cmdQueueNode* head;
    cmdQueueNode* tail;
    uint8_t size;
} cmdQueue;

typedef struct commsDriverConfig {
  char payloadID[PAYLOAD_ID_LENGTH+1];
  char fieldList[FIELD_LIST_LENGTH+1];
  uint8_t sendFieldList; // bool
  uint16_t gpsFlightModeAltitude;
  uint16_t cutdownAltitude;
  uint16_t cutdownTime;
  double LoRaFrequency;
  uint16_t LoRaImplicit;
  uint16_t LoRaCoding;
  uint16_t LoRaBandwidth;
  uint16_t LoRaSpreading;
  uint16_t LoRaLowOpt;
  uint16_t LoRaCycle;
  uint16_t LoRaSlot;
  char LoRaUplinkCode[LORA_UPLING_CODE_LENGTH+1];
  char aprsCallsign[APRS_CALLSIGN_LENGTH+1];
} commsDriverConfig;

void cmdQueueNodeFree( cmdQueueNode* node );
void cmdQueueInit( cmdQueue* queue );
void cmdQueueEnqueue( cmdQueue* queue, cmdQueueNode* node );
const cmdQueueNode* cmdQueuePeek( cmdQueue* queue );
cmdQueueNode* cmdQueueDequeue( cmdQueue* queue );
void cmdQueueAddCmd( cmdQueue* queue, const unsigned char cmd[], const unsigned char param[], const uint8_t paramSize );
void cmdQueuePopCmd( cmdQueue* queue );
void cmdQueueSendCmd( cmdQueue* queue );

void commsDriverSetConfig( commsDriverConfig* config );
void commsDriverEnqueueConfigCmds( cmdQueue* queue, commsDriverConfig* config );

void hal_startup( void )
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;               // disable the GPIO power-on default high-impedance mode
                                        // to activate previously configured port settings

    P1DIR |= 0x01;                      // Set P1.0 to output direction
    P4DIR |= 0x40;                      // Set P4.6 to output direction
    P4OUT &= ~0x40;                     // Unset P4.6
    USART0_Init();
}

void hal_PI_blink_led(void)
{
   // Write your code here
    P1OUT ^= 0x01;                      // Toggle P1.0 using XOR
    USART0_SendByte('.');
}

void hal_PI_set_led( const asn1SccT_Boolean *IN_val )
{
    if (*IN_val)
    {
        P4OUT |= 0x40;                  // Set P4.6 using OR
    }
    else
    {
        P4OUT &= ~0x40;                 // Unset P4.6 using AND
    }
    P4_6_LED_ON = *IN_val;
}

void cmdQueueNodeFree( cmdQueueNode* node )
{
    free(node->cmdData);
    free(node);
}

void cmdQueueInit( cmdQueue* q )
{
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void cmdQueueEnqueue( cmdQueue* queue, cmdQueueNode* node )
{
    node->next = NULL;
    if (queue->tail == NULL)
    {
        queue->head = node;
    }
    else
    {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->size++;
}

cmdQueueNode* cmdQueueDequeue( cmdQueue* queue )
{
    if (queue->head == NULL) // underflow
    {
        return NULL;
    }
    cmdQueueNode* node = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }
    queue->size--;

    return node;
}

const cmdQueueNode* cmdQueuePeek( cmdQueue* queue )
{
    return queue->head;
}

void cmdQueueAddCmd( cmdQueue* queue, const unsigned char cmd[], const unsigned char param[], const uint8_t paramSize )
{
    cmdQueueNode* newNode = (cmdQueueNode*)malloc(sizeof(cmdQueueNode));
    if (newNode != NULL)
    {
        unsigned char* cmdDataField = (unsigned char*)malloc(sizeof(unsigned char*) * (paramSize+CMD_CODE_LENGTH));
        if (cmdDataField == NULL) // not enought memory for newNode cmd data
        {
            free(newNode);
        }
        else
        {
            memcpy(newNode->cmdData, cmd, CMD_CODE_LENGTH);
            if (param != NULL) memcpy(newNode->cmdData+CMD_CODE_LENGTH, param, paramSize);
            newNode->cmdDataSize = paramSize+CMD_CODE_LENGTH;
            cmdQueueEnqueue(queue, newNode);
        }
    }
}

void cmdQueuePopCmd( cmdQueue* queue )
{
    cmdQueueNode* popedNode = cmdQueueDequeue(queue);
    if (popedNode != NULL)
    {
        cmdQueueNodeFree(popedNode);
    }
}

void cmdQueueSendCmd( cmdQueue* queue )
{
    const cmdQueueNode* node = cmdQueuePeek(queue);
    if (node != NULL)
    {
        USART0_SendByte('~');
        USART0_SendData(node->cmdData, node->cmdDataSize, 1);
    }
}


void commsDriverSetConfig( commsDriverConfig* config )
{
    strcpy(config->payloadID, "msp430");
    strcpy(config->fieldList, "01234569ABCD");
    config->sendFieldList = 1;
    config->gpsFlightModeAltitude = 2000;
    config->cutdownAltitude = 0;
    config->cutdownTime = 5;
    config->LoRaFrequency = 868.0;
    config->LoRaImplicit = 1;
    config->LoRaCoding = 5;
    config->LoRaBandwidth = 3;
    config->LoRaSpreading = 6;
    config->LoRaLowOpt = 0;
    config->LoRaCycle = 0;
    config->LoRaSlot = -1;
    strcpy(config->LoRaUplinkCode, "");
    strcpy(config->aprsCallsign, "");
}

void commsDriverEnqueueConfigCmds( cmdQueue* queue, commsDriverConfig* config )
{
    unsigned char temp[10];
    cmdQueueAddCmd(queue, "CH", "0", 1);

    cmdQueueAddCmd(queue, "CV", NULL, 0);

    cmdQueueAddCmd(queue, "CP", config->payloadID, PAYLOAD_ID_LENGTH);
    cmdQueueAddCmd(queue, "CF", config->fieldList, FIELD_LIST_LENGTH);
    snprintf(temp, 10, "%d", config->sendFieldList);
    cmdQueueAddCmd(queue, "CL", temp, 1);

    snprintf(temp, 10, "%d", config->gpsFlightModeAltitude);
    cmdQueueAddCmd(queue, "GF", temp, strlen(temp));

    snprintf(temp, 10, "%d", config->cutdownAltitude);
    cmdQueueAddCmd(queue, "CC", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->cutdownTime);
    cmdQueueAddCmd(queue, "CT", temp, strlen(temp));

    snprintf(temp, 10, "%.3f", config->LoRaFrequency);
    cmdQueueAddCmd(queue, "LF", temp, strlen(temp));

    snprintf(temp, 10, "%d", config->LoRaImplicit);
    cmdQueueAddCmd(queue, "LI", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->LoRaCoding);
    cmdQueueAddCmd(queue, "LE", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->LoRaBandwidth);
    cmdQueueAddCmd(queue, "LB", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->LoRaSpreading);
    cmdQueueAddCmd(queue, "LS", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->LoRaLowOpt);
    cmdQueueAddCmd(queue, "LL", temp, strlen(temp));

    snprintf(temp, 10, "%d", config->LoRaCycle);
    cmdQueueAddCmd(queue, "LT", temp, strlen(temp));
    snprintf(temp, 10, "%d", config->LoRaSlot);
    cmdQueueAddCmd(queue, "LO", temp, strlen(temp));

    cmdQueueAddCmd(queue, "LU", config->LoRaUplinkCode, LORA_UPLING_CODE_LENGTH);

    cmdQueueAddCmd(queue, "AP", config->aprsCallsign, APRS_CALLSIGN_LENGTH);

    cmdQueueAddCmd(queue, "CS", NULL, 0);
}
