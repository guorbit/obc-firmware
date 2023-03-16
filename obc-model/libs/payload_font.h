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

#ifndef PAYLOAD_FONT_H
#define PAYLOAD_FONT_H

#include <stdint.h>

/**
 * Width of digit in pixels
 */
#define PAYLOAD_DIGIT_WIDTH 20

/**
 * Height of digit in pages. One page is equal to 8 pixels
 */
#define PAYLOAD_DIGIT_HEIGHT 32

/**
 * Margin of digit in pixels
 */
#define PAYLOAD_DIGIT_MARGIN 4

/**
 * Drawing box of the digit - digit width with margins
 */
#define PAYLOAD_DIGIT_BOX_WIDTH (PAYLOAD_DIGIT_WIDTH + 2 * PAYLOAD_DIGIT_MARGIN)

/**
 * Size of glyph data
 */
#define PAYLOAD_FONT_GLYPH_SIZE 80

/**
 * Table of glyph data for all decimal digits.
 */
extern const uint8_t* const payload_font_all_digits[10];

#endif
