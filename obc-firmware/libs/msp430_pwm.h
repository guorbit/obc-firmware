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

#ifndef MSP430_PWM_H
#define MSP430_PWM_H

/**
 * Prepares MSP430 PWM to work.
 *
 * PIN configuration:
 *  P1.4 is PWM output
 */
void setup_pwm(void);

/**
 * Set PWM duty cycle.
 *
 * @param duty_cycle - requested duty cycle from 0.0 (0% fill) up to 1.0 (100% fill).
 */
void set_pwm_value(float duty_cycle);

#endif
