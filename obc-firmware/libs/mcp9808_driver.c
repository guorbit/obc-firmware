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

#include "mcp9808_driver.h"

#include "msp430_i2c.h"

#define THERMOMETER_ADDRESS (0x18)

#define THERMOMETER_REGISTER_RFU (0x00)
#define THERMOMETER_REGISTER_CONFIG (0x01)
#define THERMOMETER_REGISTER_ALERT_UPPER (0x02)
#define THERMOMETER_REGISTER_ALERT_LOWER (0x03)
#define THERMOMETER_REGISTER_CRITICAL_TEMP (0x04)
#define THERMOMETER_REGISTER_TEMPERATURE (0x05)
#define THERMOMETER_REGISTER_MANUFACTURER_ID (0x06)
#define THERMOMETER_REGISTER_DEVICE_ID (0x07)
#define THERMOMETER_REGISTER_RESOLUTION (0x08)

/**
 * Mask to access data bits from temperature register.
 *
 * MCP9808 offers 12 bits of data.
 */
#define THERMOMETER_DATA_MASK 0x0fff

/**
 * Mask to access sign bit from temperature register.
 */
#define THERMOMETER_SIGN_MASK 0x1000

/**
 * Cofficient used to convert value from temperature register to decimal value.
 *
 * Thermometer resolution is 0.0625 (power-up default)
 */
#define THERMOMETER_RESOLUTION 16.0

float msp9808_get_temperature(void)
{
    // read temperature value register using I2C
    uint8_t data[2];
    msp430_i2c_read_data(THERMOMETER_ADDRESS, THERMOMETER_REGISTER_TEMPERATURE, data, 2);

    // revert bytes of returned value
    uint16_t value = (data[0] << 8) + data[1];

    // convert to decimal value
    // see MCP9808 datasheet for more details about conversion
    float temp = 0.0;

    if(value & THERMOMETER_SIGN_MASK)
    {
        // use conversion for negative temperature
        temp = 256.0 - (value & THERMOMETER_DATA_MASK) / THERMOMETER_RESOLUTION;
    }
    else
    {
        // use conversion for positive temperature
        temp = (value & THERMOMETER_DATA_MASK) / THERMOMETER_RESOLUTION;
    }

    return temp;
}
