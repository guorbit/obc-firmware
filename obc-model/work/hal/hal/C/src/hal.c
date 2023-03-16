#include "hal.h"

#include <string.h>
#include <stdint.h>

#include <msp430.h>

#include <FreeRTOS.h>
#include <semphr.h>

#include "msp430_i2c.h"
#include "msp430_adc.h"
#include "msp430_pwm.h"
#include "oled_sdd1306_driver.h"
#include "mcp9808_driver.h"

void hal_startup(void)
{
    setup_pwm();
    setup_adc();
    msp430_i2c_init();
    setup_oled();
}

void hal_PI_get_current_temperature
(asn1SccTEMPERATURE *OUT_temperature_value)
{
    *OUT_temperature_value =  msp9808_get_temperature();
}

void hal_PI_get_current_voltage
(asn1SccVOLTAGE *OUT_current_voltage)

{
    *OUT_current_voltage = adc_get_voltage();
}

void hal_PI_oled_load_register
(const asn1SccUINT8T * register_value, asn1SccT_Boolean * success)
{
    *success = sdd1306_oled_show_data(*register_value);
}

void hal_PI_oled_set_data_enable
(const asn1SccT_Boolean * enabled, asn1SccT_Boolean * success)
{
    if(*enabled)
    {
        *success = sdd1306_oled_show_data_enabled();
    }
    else
    {
        *success = sdd1306_oled_show_data_disabled();
    }
}

void hal_PI_oled_turn_on_off
(const asn1SccT_Boolean * enabled, asn1SccT_Boolean * success)
{
    if(*enabled)
    {
        *success = sdd1306_oled_turn_on();
    }
    else
    {
        *success = ssd1306_oled_turn_off();
    }
}

void hal_PI_set_pwm
(const asn1SccDUTY_CYCLE *IN_pwm_value)
{
    set_pwm_value(*IN_pwm_value);
}
