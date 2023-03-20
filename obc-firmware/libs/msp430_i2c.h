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

#ifndef MSP430_I2C_H
#define MSP430_I2C_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Sets eUSCI_B to I2C mode.
 *
 * PIN configuration:
 *  P1.6 is SDA
 *  P1.7 is SCL
 *
 * SMCLK is used as clock source with divider value 160.
 */
void msp430_i2c_init(void);

/**
 * Write data to I2C slave
 *
 * @param address address of I2C slave
 * @param reg register number of slave to write data
 * @param data data to write
 * @param length length of data in bytes
 *
 * @return false in case of failure, otherwise true
 */
bool msp430_i2c_write_data(uint8_t address, uint8_t reg, const uint8_t* data, int length);

/**
 * Read data from I2C slave
 *
 * @param address address of I2C slave
 * @param reg register number of slave
 * @param data buffer to received data
 * @param length expected number of bytes to receive
 *
 * @return false in case of failure, otherwise true
 */
bool msp430_i2c_read_data(uint8_t address, uint8_t reg, uint8_t* data, int length);

#endif
