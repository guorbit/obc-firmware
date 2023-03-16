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

#include "msp430_adc.h"

#include <stdint.h>

#include <msp430.h>

#include <FreeRTOS.h>
#include <semphr.h>

/**
 * Value used to scale ADC conversion result.
 *
 * THe value is based on voltage divider used to measure voltage on solar panel.
 */
#define VOLTAGE_DIVIDER_RATIO 3.3

/**
 * Reference voltage value used by ADC.
 */
#define REFERENCE_VOLTAGE 2.5

/**
 * Precission of MSP430 ADC converter.
 */
#define ADC_PRECISSION_BITS 12

/**
 * The internal state of ADC module.
 */
struct MSP430_ADCState
{
    /**
     * Semaphore used to synchronize function call with ADC interrupt.
     */
    SemaphoreHandle_t semaphore;
    /**
     * Buffer used to static allocation of semaphore.
     */
    StaticSemaphore_t semaphore_buffer;
    /**
     * The value to return result of ADC conversion from ADC interrupt.
     */
    volatile uint16_t voltage_raw_value;
};

static __attribute__((persistent))
struct MSP430_ADCState msp430_adc_state = {0};

void setup_adc(void)
{
    // Create semaphore
    msp430_adc_state.semaphore = xSemaphoreCreateBinaryStatic(&msp430_adc_state.semaphore_buffer);
    // Configure P1.3 for ADC
    // P1.3 is A3 ADC channel
    P1SEL1 |= BIT3;
    P1SEL0 |= BIT3;

    // By default, REFMSTR=1 => REFCTL is used to configure the internal reference
    // If ref generator busy, WAIT
    while(REFCTL0 & REFGENBUSY);

    // Select internal ref = 2.5V, Internal Reference ON
    REFCTL0 |= REFVSEL_2 | REFON;

    ADC12CTL0 = ADC12SHT0_2 | ADC12ON;
    // ADCCLK = MODOSC; sampling timer
    ADC12CTL1 = ADC12SHP;
    // 12-bit conversion results
    ADC12CTL2 |= ADC12RES_2;
    // Enable ADC conv complete interrupt
    ADC12IER0 |= ADC12IE0;
    // A1 ADC input select (A3 channel will be in ADC12MEM12) Vref+=2.5V; Vref-=AVSS (0.0V)
    ADC12MCTL0 |= ADC12INCH_3 | ADC12VRSEL_1;

    // Wait for reference generator to settle
    while(!(REFCTL0 & REFGENRDY));
}

float adc_get_voltage(void)
{
    // start conversion
    ADC12CTL0 |= ADC12ENC | ADC12SC;

    // wait for interrupt
    xSemaphoreTake(msp430_adc_state.semaphore, portMAX_DELAY);


    float voltage = (msp430_adc_state.voltage_raw_value * REFERENCE_VOLTAGE)
                    / (1 << ADC_PRECISSION_BITS) * VOLTAGE_DIVIDER_RATIO;

    return voltage;
}

void __attribute__((interrupt(ADC12_VECTOR))) adc12_ISR(void)
{
    BaseType_t higher_priority_task_woken = pdFALSE;

    switch(__even_in_range(ADC12IV, ADC12IV_ADC12RDYIFG))
    {
        case ADC12IV_ADC12IFG0:
            msp430_adc_state.voltage_raw_value = ADC12MEM0;


            xSemaphoreGiveFromISR(msp430_adc_state.semaphore, &higher_priority_task_woken);
            break;

        default:
            break;
    }

    portYIELD_FROM_ISR(higher_priority_task_woken);
}
