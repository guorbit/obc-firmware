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

#ifndef OLED_SDD1306_DRIVER_H
#define OLED_SDD1306_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * This function is used at a boot time to initialize hardware and all structures
 * required to communication with SDD1306 OLED.
 */
void setup_oled(void);

/**
 * Function used to indicate 'data enabled' feature.
 *
 * @returns true in case of success, otherwize false
 */
bool sdd1306_oled_show_data_enabled(void);

/**
 * Function used to indicate 'data disabled' feature.
 *
 * @returns true in case of success, otherwize false
 */
bool sdd1306_oled_show_data_disabled(void);

/**
 * Function used to load register data.
 *
 * @param register_value value to be displayed
 * @returns true in case of success, otherwize false
 */
bool sdd1306_oled_show_data(uint8_t register_value);

/**
 * Turn on payload.
 *
 * @returns true in case of success, otherwize false
 */
bool sdd1306_oled_turn_on(void);

/**
 * Turn off payload.
 *
 * @returns true in case of success, otherwize false
 */
bool ssd1306_oled_turn_off(void);

#endif
