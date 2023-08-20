/*
 * https://stackoverflow.com/questions/31032431/uart-for-msp430fr5969
 */

#include "msp430_uart.h"

#include <msp430.h>
#include <FreeRTOS.h>
#include <semphr.h>

void USART0_Init () {
    P2SEL1 |= BIT0| BIT1;                   // Configure UART pins
    P2SEL0 &= ~(BIT0| BIT1);

    // Configure USCI_A0 for UART mode
    UCA0CTLW0 = UCSWRST;                    // Put eUSCI in reset
    UCA0CTLW0 |= UCSSEL__SMCLK;             // CLK = SMCLK
    UCA0BR0 = 4;                            // 8000000/16/115200
    UCA0BR1 = 0x00;
    UCA0MCTLW |= 0x55;                      // UCOS16 | UCBRF_1;
    UCA0CTLW0 &= ~UCSWRST;                  // Initialize eUSCI
    // UCA0IE |= UCRXIE;                    // Enable USCI_A0 RX interrupt
}

void USART0_SendByte (unsigned char data) {
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = data;
}

void USART0_SendData (unsigned char data[], unsigned char length, int lineterm) {
    unsigned char i;
    for(i=0; i<length; i++) {
        USART0_SendByte(data[i]);
    }

    if (lineterm)
    {
        USART0_SendByte('\n');                  // new line
        USART0_SendByte('\r');                  // carriage return
    }
}

unsigned char USART0_ReadByte (void) {
    unsigned char c = UCA0RXBUF;
    return c;
}