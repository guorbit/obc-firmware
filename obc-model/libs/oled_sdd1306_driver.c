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

#include "oled_sdd1306_driver.h"

#include <msp430.h>

#include <FreeRTOS.h>
#include <task.h>

#include "msp430_i2c.h"
#include "payload_font.h"

#define OLED_SDD1306_I2C_ADDRESS 0x3c

#define OLED_SDD1306_REGISTER_CONFIG 0x00
#define OLED_SDD1306_REGISTER_DATA 0x40

#define OLED_COMMAND_SET_COLUMN ((uint8_t)0x21)
#define OLED_COMMAND_SET_PAGE ((uint8_t)0x22)
#define OLED_COMMAND_TURN_ON_OFF ((uint32_t)0xaf)

#define OLED_SCREEN_WIDTH 128
#define OLED_SCREEN_HEIGHT 64

#define OLED_WAIT_PERIOD_MS 5
#define OLED_INIT_WAIT_PERIOD_MS 10

#define PAYLOAD_TEXT_POSITION_X 26
#define PAYLOAD_TEXT_POSITION_Y 24

#define PAYLOAD_AUX_DATA_SIZE 128

#define PAYLOAD_DATA_ENABLED_BAR_HEIGHT 15

/**
 * Auxilary data used to clear screen or digit.
 */
__attribute__((persistent))
uint8_t const payload_font_zeros[PAYLOAD_AUX_DATA_SIZE] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/**
 * Auxilary data used to turn on all pixels.
 */
__attribute__((persistent))
const uint8_t payload_font_ones[PAYLOAD_AUX_DATA_SIZE] =
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/**
 * Static data used to initialize SDD1306 OLED.
 */
static __attribute__((persistent)) const uint8_t OLED_INIT_BUFFER[] =
{
    0xae, // on
    0xa8, 0x3f, // multiplex ratio
    0xd3, 0x00, // display offset
    0x40, // start line
    0xa1, // segment re-map
    0xc8, // set COM output scan direction
    0xda, 0x12, // set COM pins hardware configuration
    0x81, 0xff, // set contrast control
    0xa4, // set entire display on/off
    0xa6, // set normal inverse display
    0xd5, 0x80, // set display clock divide ratio/oscillator frequency
    0x8d, 0x14, // set charge pump
    0xaf, // set display on
    0x20, 0x00  // memory addressing mode - horizontal addressing mode
};

/**
 * Set drawing rectangle.
 *
 * The row parameters should be multiple of 8. These parameters are converted to pages,
 * which are used by OLED for addressing. 1 page is equal to 8 pixels.
 *
 * @param first_column first column of rectangle in pixels
 * @param last_column last column of rectangle in pixels
 * @param first_row first row of rectangle in pixels.
 * @param last_row last_row of rectangle in pixels.
 *
 * @returns true in case of success, otherwize false
 */
static bool oled_set_drawing_rectangle(uint8_t first_column, uint8_t last_column,
                                       uint8_t first_row, uint8_t last_row)
{
    uint8_t command_set_column[] = {OLED_COMMAND_SET_COLUMN,
                                    first_column,
                                    last_column
                                   };

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_CONFIG,
                              command_set_column,
                              sizeof(command_set_column)))
    {
        return false;
    }

    uint8_t command_set_page[] = {OLED_COMMAND_SET_PAGE,
                                  first_row / 8,
                                  last_row / 8
                                 };

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_CONFIG,
                              command_set_page,
                              sizeof(command_set_page)))
    {
        return false;
    }

    return true;
}

static bool oled_display_digit(uint8_t digit, uint8_t position)
{
    uint8_t column = (position * PAYLOAD_DIGIT_BOX_WIDTH) + PAYLOAD_TEXT_POSITION_X;

    if(!oled_set_drawing_rectangle(column,
                                   column + PAYLOAD_DIGIT_WIDTH - 1,
                                   PAYLOAD_TEXT_POSITION_Y,
                                   PAYLOAD_TEXT_POSITION_Y + PAYLOAD_DIGIT_HEIGHT - 1))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_all_digits[digit],
                              PAYLOAD_FONT_GLYPH_SIZE))
    {
        return false;
    }

    return true;
}

static bool oled_clear_digit(uint8_t position)
{
    uint8_t column = (position * PAYLOAD_DIGIT_BOX_WIDTH) + PAYLOAD_TEXT_POSITION_X;

    if(!oled_set_drawing_rectangle(column,
                                   column + PAYLOAD_DIGIT_WIDTH - 1,
                                   PAYLOAD_TEXT_POSITION_Y,
                                   PAYLOAD_TEXT_POSITION_Y + PAYLOAD_DIGIT_HEIGHT - 1))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_zeros,
                              PAYLOAD_FONT_GLYPH_SIZE))
    {
        return false;
    }

    return true;
}

void setup_oled(void)
{
    P1DIR |= BIT5; // configure P1.5 as display reset bit
}

bool sdd1306_oled_show_data_enabled(void)
{
    if(!oled_set_drawing_rectangle(0, OLED_SCREEN_WIDTH - 1, 0, PAYLOAD_DATA_ENABLED_BAR_HEIGHT))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_ones,
                              PAYLOAD_AUX_DATA_SIZE))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_ones,
                              PAYLOAD_AUX_DATA_SIZE))
    {
        return false;
    }

    return true;
}

bool sdd1306_oled_show_data_disabled(void)
{
    if(!oled_set_drawing_rectangle(0, OLED_SCREEN_WIDTH - 1, 0, PAYLOAD_DATA_ENABLED_BAR_HEIGHT))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_zeros,
                              PAYLOAD_AUX_DATA_SIZE))
    {
        return false;
    }

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_DATA,
                              payload_font_zeros,
                              PAYLOAD_AUX_DATA_SIZE))
    {
        return false;
    }

    if(!oled_clear_digit(2))
    {
        return false;
    }

    if(!oled_clear_digit(1))
    {
        return false;
    }

    if(!oled_clear_digit(0))
    {
        return false;
    }

    return true;
}

bool sdd1306_oled_show_data(uint8_t register_value)
{
    const uint8_t third_digit = register_value / 100;
    const uint8_t second_digit = (register_value % 100) / 10;
    const uint8_t first_digit = register_value % 10;

    if(!oled_display_digit(first_digit, 2))
    {
        return false;
    }

    if(!oled_display_digit(second_digit, 1))
    {
        return false;
    }

    if(!oled_display_digit(third_digit, 0))
    {
        return false;
    }

    return true;
}

bool sdd1306_oled_turn_on(void)
{
    // high on reset pin
    P1OUT |= BIT5;
    vTaskDelay(OLED_WAIT_PERIOD_MS / portTICK_PERIOD_MS);
    // low on reset pin (oled initialization)
    P1OUT &= ~BIT5;
    vTaskDelay(OLED_WAIT_PERIOD_MS / portTICK_PERIOD_MS);
    // high on reset pin
    P1OUT |= BIT5;
    vTaskDelay(OLED_WAIT_PERIOD_MS / portTICK_PERIOD_MS);

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_CONFIG,
                              OLED_INIT_BUFFER,
                              sizeof(OLED_INIT_BUFFER)))
    {
        return false;
    }

    vTaskDelay(OLED_INIT_WAIT_PERIOD_MS / portTICK_PERIOD_MS);

    // clear whole screen
    if(!oled_set_drawing_rectangle(0,
                                   OLED_SCREEN_WIDTH - 1,
                                   0,
                                   OLED_SCREEN_HEIGHT - 1))
    {
        return false;
    }

    for(int i = 0; i < 8; ++i)
    {
        if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                                  OLED_SDD1306_REGISTER_DATA,
                                  payload_font_zeros,
                                  PAYLOAD_AUX_DATA_SIZE))
        {
            return false;
        }
    }

    return true;
}

bool ssd1306_oled_turn_off(void)
{
    uint8_t command_data[1] = {OLED_COMMAND_TURN_ON_OFF};

    if(!msp430_i2c_write_data(OLED_SDD1306_I2C_ADDRESS,
                              OLED_SDD1306_REGISTER_CONFIG,
                              command_data,
                              sizeof(command_data)))
    {
        return false;
    }

    vTaskDelay(OLED_WAIT_PERIOD_MS / portTICK_PERIOD_MS);

    // low on reset pin
    P1OUT &= ~BIT5;

    return true;
}
