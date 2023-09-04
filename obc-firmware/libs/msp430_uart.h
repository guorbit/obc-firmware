/*
 * https://stackoverflow.com/questions/31032431/uart-for-msp430fr5969
 */

#ifndef MSP430_UART_H
#define MSP430_UART_H

/**
  * Prepares MSP430 USART0 to work.
  */
void USART0_Init ();

/**
  * Sends a single byte over USART0 TX.
  *
  * @param data - the byte to transmit.
  */
void USART0_SendByte (unsigned char data);

/**
  * Send multiple bytes of data over USART0 TX.
  *
  * @param data - the array of bytes to transmit.
  * @param length - the amount of bytes to transmit.
  */
void USART0_SendData (unsigned char data[], unsigned char length, int lineterm);

/**
 * Reads a single byte from USART0 RX
 *
 * @return read byte
 */
unsigned char USART0_ReadByte (void);

/**
  * Prepares MSP430 USART1 to work.
  */
void USART1_Init();

/**
  * Sends a single byte over USART1 TX.
  *
  * @param data - the byte to transmit.
  */
void USART1_SendByte (unsigned char data);

/**
  * Send multiple bytes of data over USART1 TX.
  *
  * @param data - the array of bytes to transmit.
  * @param length - the amount of bytes to transmit.
  */
void USART1_SendData (unsigned char data[], unsigned char length, int lineterm);

/**
 * Reads a single byte from USART1 RX
 *
 * @return read byte
 */
unsigned char USART1_ReadByte (void);

#endif
