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

void USART1_Init() {
    // setup UART A1
    UCA1CTLW0 |= UCSWRST;                   // put UART A1 into SW reset

    UCA1CTLW0 |= UCSSEL__SMCLK;             // CLK = SMCLK
    UCA1BR0 = 4;                            // 8000000/16/115200
    UCA1BR1 = 0x00;
    UCA1MCTLW |= 0x55;                      // UCOS16 | UCBRF_1;

    // setup pins
    P2SEL1 |= BIT5 + BIT6;
    P2SEL0 &= ~BIT5 + BIT6;                         // UART A1 TX on P2.5

    PM5CTL0 &= ~LOCKLPM5;                   // turn on I/O

    UCA1CTLW0 &= ~UCSWRST;                  // get UART A1 out of reset
}

void USART1_SendByte (unsigned char data) {
    while(!(UCA1IFG & UCTXIFG));
    UCA1TXBUF = data;
}

void USART1_SendData (unsigned char data[], unsigned char length, int lineterm) {
    unsigned char i;
    for(i=0; i<length; i++) {
        USART1_SendByte(data[i]);
    }

    if (lineterm)
    {
        USART1_SendByte('\n');                  // new line
        USART1_SendByte('\r');                  // carriage return
    }
}

unsigned char USART1_ReadByte (void) {
    unsigned char c = UCA1RXBUF;
    return c;
}
