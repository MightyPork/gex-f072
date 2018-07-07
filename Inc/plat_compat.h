//
// Created by MightyPork on 2018/07/07.
//

#ifndef GEX_PLAT_COMPAT_H
#define GEX_PLAT_COMPAT_H

#define PLAT_AHB_MHZ 48
#define PLAT_APB1_MHZ 48

#include <stm32f0xx.h>
#include <stm32f0xx_ll_adc.h>
#include <stm32f0xx_ll_bus.h>
#include <stm32f0xx_ll_comp.h>
#include <stm32f0xx_ll_cortex.h>
#include <stm32f0xx_ll_crc.h>
#include <stm32f0xx_ll_crs.h>
#include <stm32f0xx_ll_dac.h>
#include <stm32f0xx_ll_dma.h>
#include <stm32f0xx_ll_exti.h>
#include <stm32f0xx_ll_gpio.h>
#include <stm32f0xx_ll_i2c.h>
#include <stm32f0xx_ll_iwdg.h>
#include <stm32f0xx_ll_pwr.h>
#include <stm32f0xx_ll_rcc.h>
#include <stm32f0xx_ll_rtc.h>
#include <stm32f0xx_ll_spi.h>
#include <stm32f0xx_ll_system.h>
#include <stm32f0xx_ll_tim.h>
#include <stm32f0xx_ll_usart.h>
#include <stm32f0xx_ll_utils.h>
#include <stm32f0xx_ll_wwdg.h>

#define GEX_PLAT_F072 1

// size, determines position of the flash storage
#define FLASH_SIZE (128*1024)
#define SETTINGS_BLOCK_SIZE (1024*2) // this must be a multiple of FLASH pages
#define SETTINGS_FLASH_ADDR (0x08000000 + FLASH_SIZE - SETTINGS_BLOCK_SIZE)

// Number of GPIO ports A,B,C,D,E,F
#define PORTS_COUNT 6
#define PLAT_USB_PU_CTL 1

#if defined(GEX_PLAT_F072_DISCOVERY)
    // platform name for the version string
    #define GEX_PLATFORM "STM32F072-Discovery"

    // Lock jumper config
    #define LOCK_JUMPER_PORT 'A'
    #define LOCK_JUMPER_PIN  0
    #define PLAT_LOCK_BTN 1 // toggle button instead of a jumper
    #define PLAT_LOCK_1CLOSED 1 // toggle button active in log. 1

    // Status LED config
    #define STATUS_LED_PORT 'C'
    #define STATUS_LED_PIN  6 // RED LED "UP"
#elif defined(GEX_PLAT_F072_HUB)
    // platform name for the version string
    #define GEX_PLATFORM "STM32F072-HUB"

    #define PLAT_FULL_XTAL 1

    // Lock jumper config
    #define LOCK_JUMPER_PORT 'D'
    #define LOCK_JUMPER_PIN  2
    #define PLAT_LOCK_BTN 1 // toggle button instead of a jumper
    #define PLAT_LOCK_1CLOSED 0 // toggle button active in log. 1

    // Status LED config
    #define STATUS_LED_PORT 'A'
    #define STATUS_LED_PIN  15 // RED LED "UP"
#elif defined(GEX_PLAT_F072_ZERO)
    // platform name for the version string
    #define GEX_PLATFORM "STM32F072-ZERO"

    #define PLAT_FULL_XTAL 1

    // Lock jumper config
    #define LOCK_JUMPER_PORT 'D'
    #define LOCK_JUMPER_PIN  2
    #define PLAT_LOCK_BTN 1 // toggle button instead of a jumper
    #define PLAT_LOCK_1CLOSED 1 // toggle button active in log. 1

    // Status LED config
    #define STATUS_LED_PORT 'A'
    #define STATUS_LED_PIN  15

    #define SUPPORT_NRF 1
#else
    #error Bad platform
#endif

// Debug UART
#define DEBUG_USART_BAUD 115200
#define DEBUG_USART USART1
#define DEBUG_USART_RSC R_USART1
#define DEBUG_USART_PORT 'A'
#define DEBUG_USART_PIN  9
#define DEBUG_USART_AF  1
#define DEBUG_USART_PCLK PLAT_APB1_HZ

// FreeRTOS config
#define PLAT_FREERTOS_LOWEST_INTERRUPT_PRIORITY          3
#define PLAT_FREERTOS_MAX_SYSCALL_INTERRUPT_PRIORITY     1
#define PLAT_FREERTOS_PRIO_BITS                          2
#define PLAT_FREERTOS_USE_PORT_OPTIMISED_TASK_SELECTION  0

#endif //GEX_PLAT_COMPAT_H
