// This is a GEX units manifest file
// For a unit to be included in the firmware, it's uppercase name
// must be included in the GEX_UNITS list in build.mk, and it must have 
// a section here.

#ifdef ENABLE_UNIT_1WIRE
#include "1wire/unit_1wire.h"
#endif

#ifdef ENABLE_UNIT_ADC
#include "adc/unit_adc.h"
#endif

#ifdef ENABLE_UNIT_DAC
#include "dac/unit_dac.h"
#endif

#ifdef ENABLE_UNIT_DIN
#include "din/unit_din.h"
#endif

#ifdef ENABLE_UNIT_DOUT
#include "dout/unit_dout.h"
#endif

#ifdef ENABLE_UNIT_FCAP
#include "fcap/unit_fcap.h"
#endif

#ifdef ENABLE_UNIT_I2C
#include "i2c/unit_i2c.h"
#endif

#ifdef ENABLE_UNIT_NEOPIXEL
#include "neopixel/unit_neopixel.h"
#endif

#ifdef ENABLE_UNIT_PWMDIM
#include "pwmdim/unit_pwmdim.h"
#endif

#ifdef ENABLE_UNIT_SIPO
#include "sipo/unit_sipo.h"
#endif

#ifdef ENABLE_UNIT_SPI
#include "spi/unit_spi.h"
#endif

#ifdef ENABLE_UNIT_TEMPLATE
#include "template/unit_template.h"
#endif

#ifdef ENABLE_UNIT_TEST
#include "test/unit_test.h"
#endif

#ifdef ENABLE_UNIT_TOUCH
#include "touch/unit_touch.h"
#endif

#ifdef ENABLE_UNIT_USART
#include "usart/unit_usart.h"
#endif

