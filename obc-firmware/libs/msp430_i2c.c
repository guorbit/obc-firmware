/*
Copyright (C) 2020 European Space Agency - <maxime.perrotin@esa.int>

This file is part of MSP430 Demo-Sat project.

MSP430 Demo-Sat is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MSP430 Demo-Sat is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with MSP430 Demo-Sat. If not, see <https://www.gnu.org/licenses/>.
*/

#include "msp430_i2c.h"

#include <string.h>

#include <msp430.h>

#include <FreeRTOS.h>
#include <semphr.h>

enum MSP430_I2CMode
{
    MSP430_I2C_DATA_READ,
    MSP430_I2C_DATA_WRITE
};

struct MSP430_I2CState
{
    enum MSP430_I2CMode mode;
    uint8_t register_addr;
    bool register_addr_sent;
    uint8_t* read_buffer;
    const uint8_t* write_buffer;
    int buffer_index;
    int buffer_length;
    StaticSemaphore_t semaphore_buffer;
    SemaphoreHandle_t semaphore;
    bool operation_success;
};

static __attribute__((persistent))
struct MSP430_I2CState msp430_i2c_state = {0};

void msp430_i2c_init(void)
{
    msp430_i2c_state.mode = MSP430_I2C_DATA_READ;
    msp430_i2c_state.register_addr = 0;
    msp430_i2c_state.register_addr_sent = false;
    msp430_i2c_state.read_buffer = NULL;
    msp430_i2c_state.write_buffer = NULL;
    msp430_i2c_state.buffer_index = 0;
    msp430_i2c_state.buffer_length = 0;
    // Create semaphore
    msp430_i2c_state.semaphore = xSemaphoreCreateBinaryStatic(&msp430_i2c_state.semaphore_buffer);
    msp430_i2c_state.operation_success = false;

    // Configure GPIO
    // I2C pins
    P1SEL1 |= BIT6 | BIT7;

    // put eUSCI_B in reset state
    UCB0CTLW0 = UCSWRST;

    // I2C master mode, SMCLK
    UCB0CTLW0 |= UCMODE_3 | UCMST | UCSSEL__SMCLK | UCSYNC;

    // I2C timeout
    UCB0CTLW1 |= UCCLTO0;

    // baudrate 100 kHz
    UCB0BRW = 0x50; // 8MHz / 160 = 100kHz

    // clear reset register
    UCB0CTLW0 &= ~UCSWRST;

    UCB0IE |= UCNACKIE;
}

bool msp430_i2c_write_data(uint8_t address, uint8_t reg, const uint8_t* data, int length)
{
    msp430_i2c_state.mode = MSP430_I2C_DATA_WRITE;
    msp430_i2c_state.register_addr = reg;
    msp430_i2c_state.register_addr_sent = false;
    msp430_i2c_state.read_buffer = NULL;
    msp430_i2c_state.write_buffer = data;
    msp430_i2c_state.buffer_index = 0;
    msp430_i2c_state.buffer_length = length;
    msp430_i2c_state.operation_success = false;

    // Set slave address
    UCB0I2CSA = address;
    // Clear any pending interrupts
    UCB0IFG &= ~(UCTXIFG + UCRXIFG);
    // Disable RX interrupt
    UCB0IE &= ~UCRXIE;
    // Enable TX interrupt
    UCB0IE |= UCTXIE;
    // I2C TX, start condition
    UCB0CTLW0 |= UCTR + UCTXSTT;

    // wait for end of the transfer
    xSemaphoreTake(msp430_i2c_state.semaphore, portMAX_DELAY);

    return msp430_i2c_state.operation_success;
}

bool msp430_i2c_read_data(uint8_t address, uint8_t reg, uint8_t* data, int length)
{
    msp430_i2c_state.mode = MSP430_I2C_DATA_READ;
    msp430_i2c_state.register_addr = reg;
    msp430_i2c_state.register_addr_sent = false;
    msp430_i2c_state.read_buffer = data;
    msp430_i2c_state.write_buffer = NULL;
    msp430_i2c_state.buffer_index = 0;
    msp430_i2c_state.buffer_length = length;
    msp430_i2c_state.operation_success = false;

    // Set slave address
    UCB0I2CSA = address;
    // Clear any pending interrupts
    UCB0IFG &= ~(UCTXIFG + UCRXIFG);
    // Disable RX interrupt
    UCB0IE &= ~UCRXIE;
    // Enable TX interrupt
    UCB0IE |= UCTXIE;
    // I2C TX, start condition
    UCB0CTLW0 |= UCTR + UCTXSTT;

    // wait for end of the transfer
    xSemaphoreTake(msp430_i2c_state.semaphore, portMAX_DELAY);

    return msp430_i2c_state.operation_success;
}

static void msp430_i2c_nack_received(BaseType_t* higher_priority_task_woken)
{
    msp430_i2c_state.operation_success = false;

    xSemaphoreGiveFromISR(msp430_i2c_state.semaphore, higher_priority_task_woken);
}

static void msp430_i2c_receive_data(BaseType_t* higher_priority_task_woken)
{
    uint8_t received_byte;
    received_byte = UCB0RXBUF;

    if(msp430_i2c_state.buffer_index < msp430_i2c_state.buffer_length)
    {
        msp430_i2c_state.read_buffer[msp430_i2c_state.buffer_index] = received_byte;
        ++msp430_i2c_state.buffer_index;
    }

    if(msp430_i2c_state.buffer_index + 1 == msp430_i2c_state.buffer_length)
    {
        // this is the last byte
        // Transmit stop
        UCB0CTLW0 |= UCTXSTP;
    }

    if(msp430_i2c_state.buffer_index == msp430_i2c_state.buffer_length)
    {
        // Disable RX Interrupts
        UCB0IE &= ~UCRXIE;

        msp430_i2c_state.operation_success = true;

        xSemaphoreGiveFromISR(msp430_i2c_state.semaphore, higher_priority_task_woken);
    }
}

static void msp430_i2c_transmit_data(BaseType_t* higher_priority_task_woken)
{
    if(!msp430_i2c_state.register_addr_sent)
    {
        UCB0TXBUF = msp430_i2c_state.register_addr;
        msp430_i2c_state.register_addr_sent = true;
        return;
    }

    if(msp430_i2c_state.mode == MSP430_I2C_DATA_WRITE)
    {
        if(msp430_i2c_state.buffer_index == msp430_i2c_state.buffer_length)
        {
            // Send stop condition
            UCB0CTLW0 |= UCTXSTP;
            // disable TX interrupt
            UCB0IE &= ~UCTXIE;

            msp430_i2c_state.operation_success = true;

            xSemaphoreGiveFromISR(msp430_i2c_state.semaphore, higher_priority_task_woken);
        }
        else
        {
            UCB0TXBUF = msp430_i2c_state.write_buffer[msp430_i2c_state.buffer_index];
            ++msp430_i2c_state.buffer_index;
        }
    }
    else
    {
        // Enable RX interrupt
        UCB0IE |= UCRXIE;
        // Disable TX interrupt
        UCB0IE &= ~UCTXIE;
        // Switch to receiver
        UCB0CTLW0 &= ~UCTR;
        // Send repeated start
        UCB0CTLW0 |= UCTXSTT;

        if(msp430_i2c_state.buffer_length == 1)
        {
            //Must send stop since this is the N-1 byte
            while((UCB0CTLW0 & UCTXSTT));

            // Send stop condition
            UCB0CTLW0 |= UCTXSTP;
        }
    }
}

void __attribute__((interrupt(USCI_B0_VECTOR)))
msp430_i2c_isr(void)
{
    BaseType_t higher_priority_task_woken = pdFALSE;

    switch(__even_in_range(UCB0IV, USCI_I2C_USBIT9IFG))
    {
        case USCI_I2C_UCNACKIFG:
            msp430_i2c_nack_received(&higher_priority_task_woken);
            break;

        case USCI_I2C_UCRXIFG0:
            msp430_i2c_receive_data(&higher_priority_task_woken);
            break;

        case USCI_I2C_UCTXIFG0:
            msp430_i2c_transmit_data(&higher_priority_task_woken);
            break;

        default:
            break;
    }

    portYIELD_FROM_ISR(higher_priority_task_woken);
}
