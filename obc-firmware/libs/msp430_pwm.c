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

int msp430_pwm_period_cycles;
int msp430_pwm_clock_divide_by;

void setup_pwm(int period_us)
{
    // Expansion Register: divide by 8
    msp430_pwm_clock_divide_by = 8;
    TB0EX0 = TBIDEX__8;
    // SMCLK (f = ~1MHz), up mode, clear TBR
    TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR | ID__8;
    // reset/set
    TB0CCTL1 = OUTMOD_7;
    // enable global interrupts
    __enable_interrupt();
    // disable CCR0 interrupt
    TB0CTL &= ~TBIE;

    // PWM Period
    msp430_pwm_period_cycles = period_us;
    TB0CCR0 = period_us / msp430_pwm_clock_divide_by;
    // PWM duty cycle
    TB0CCR1 = 0;

    // P1.4 output
    P1DIR |= BIT4;
    // P1.4 options select
    P1SEL0 |= BIT4;
    P1SEL1 &= ~BIT4;
}

void set_pwm_duty_cycle(float duty_cycle_percent)
{
    // disable CCR0 interrupt
    TB0CTL &= ~TBIE;
    uint16_t pulse_width_us = duty_cycle_percent * msp430_pwm_period_cycles / msp430_pwm_clock_divide_by;
    // PWM duty cycle
    TB0CCR1 = pulse_width_us;
}

void set_pwm_pulse_width(int pulse_width_us)
{
    // disable CCR0 interrupt
    TB0CTL &= ~TBIE;
    // PWM pulse width
    TB0CCR1 = pulse_width_us / msp430_pwm_clock_divide_by;
}

void pulse_single_width(int pulse_width_us)
{
    // enable CCR0 interrupt
    TB0CTL |= TBIE;
    // CCR1 PWM duty cycle
    TB0CCR1 = pulse_width_us / msp430_pwm_clock_divide_by;
}

#pragma vector=TIMER0_B0_VECTOR
__interrupt void Timer_B(void)
{
    if (TB0CTL == TBIFG) // should automatically reset interrupt flag with read
    {
        // hold the output low (in reset/set mode)
        TB0CCR1 = 0;
    }
    // manually reset interrupt flag
    TB0CTL &= ~TBIFG;
    // disable CCR0 interrupt
    TB0CTL &= ~TBIE;
}
