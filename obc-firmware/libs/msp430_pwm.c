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

#include "msp430_pwm.h"

#include <stdint.h>

#include <msp430.h>

#define MSP430_PWM_RESOLUTION 1000

void setup_pwm(void)
{
    // PWM - 250 kHz
    // Configure GPIO
    // PWM pin
    // P1.4 output
    P1DIR |= BIT4;
    // P1.4 options select
    P1SEL0 |= BIT4;

    // PWM Period
    TB0CCR0 = 1000 - 1;
    // CCR1 reset/set
    TB0CCTL1 = OUTMOD_7;
    // CCR1 PWM duty cycle
    TB0CCR1 = 0;
    // Expansion Register - 4
    TB0EX0 = TBIDEX__4;
    // SMCLK, up mode, clear TBR
    TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR | ID__8;
}

void set_pwm_value(float duty_cycle)
{
    uint16_t pwm_value = duty_cycle * MSP430_PWM_RESOLUTION;

    // CCR1 PWM duty cycle
    TB0CCR1 = pwm_value;
}
