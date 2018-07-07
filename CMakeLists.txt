# This is a dummy CmakeLists.txt file for CLion.
# It does not work, don't even try.

cmake_minimum_required(VERSION 3.9)
project(GEX_F072)

set(CMAKE_CXX_STANDARD 11)

add_definitions(
        -DUSE_HAL_DRIVER=1
        -DSTM32F072xB
        -D__weak=__attribute__\(\(weak\)\)
        -D__packed=__attribute__\(\(__packed__\)\)
        -D__COUNTER__=__LINE__
        -DUSBD_SUPPORT_USER_STRING=1
        -DASSERT_FILENAMES=1
        -DDEBUG_VFS=1
        -DDEBUG_MALLOC=1
        -DUSE_FULL_ASSERT=1
        -DUSE_FULL_LL_DRIVER=1
        -DVERBOSE_HARDFAULT=1
        -DUSE_STACK_MONITOR=1
        -DUSE_DEBUG_UART=1
        -DGEX_PLAT_F072_ZERO
        -DHAL_TSC_MODULE_ENABLED

        -DENABLE_UNIT_1WIRE=1
        -DENABLE_UNIT_ADC=1
        -DENABLE_UNIT_DAC=1
        -DENABLE_UNIT_DIGITAL_IN=1
        -DENABLE_UNIT_DIGITAL_OUT=1
        -DENABLE_UNIT_FCAP=1
        -DENABLE_UNIT_I2C=1
        -DENABLE_UNIT_NEOPIXEL=1
        -DENABLE_UNIT_SIMPLE_PWM=1
        -DENABLE_UNIT_SIPO=1
        -DENABLE_UNIT_SPI=1
        -DENABLE_UNIT_TEMPLATE=1
        -DENABLE_UNIT_TEST=1
        -DENABLE_UNIT_TOUCH=1
        -DENABLE_UNIT_USART=1
)

FILE(GLOB_RECURSE SOURCE_FILES
        Inc/*.h
        Drivers/*.c
        Drivers/*.h
        Middlewares/*.c
        Middlewares/*.h
        GexCore/*.c
        GexCore/*.h
        GexUnits/*.c
        GexUnits/*.h
        Src/*.c
        Src/*.h
)

include_directories(
        # System includes folder
        /usr/arm-none-eabi/include/

        # CMSIS + HAL
        Drivers/CMSIS/Include
        Drivers/CMSIS/Device/ST/STM32F0xx/Include
        Drivers/STM32F0xx_HAL_Driver/Inc
        Drivers/STM32F0xx_HAL_Driver/Inc/Legacy

        # USB Library
        GexCore/USB/STM32_USB_Device_Library/Core/Inc
        # USB Device Classes
        GexCore/USB/STM32_USB_Device_Library/Class/AUDIO/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/CDC/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/CustomHID/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/DFU/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/HID/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/MSC/Inc
        GexCore/USB/STM32_USB_Device_Library/Class/MSC_CDC

        # Other vendor libraries
        GexCore/USB/STM32_TouchSensing_Library/inc

        # FreeRTOS
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0

        # Application
        GexCore
        GexCore/USB
        GexCore/utils
        GexCore/TinyFrame
        GexCore/framework
        GexCore/platform
        GexCore/tasks
        Inc
        GexUnits
)

add_executable(main ${SOURCE_FILES})
