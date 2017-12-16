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
        -DVERBOSE_ASSERT=1
        -DDEBUG_VFS=1
        -DUSE_FULL_ASSERT=1
        -DUSE_FULL_LL_DRIVER=1
        -DVERBOSE_HARDFAULT=1
        -DUSE_STACK_MONITOR=1
        -DUSE_DEBUG_UART=1
        -DGEX_PLAT_F072_DISCOVERY
)

FILE(GLOB_RECURSE SOURCE_FILES
        Inc/*.h
        Drivers/*.c
        Drivers/*.h
        Middlewares/*.c
        Middlewares/*.h
        User/*.c
        User/*.h
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
        User/USB/STM32_USB_Device_Library/Core/Inc
        # USB Device Classes
        User/USB/STM32_USB_Device_Library/Class/AUDIO/Inc
        User/USB/STM32_USB_Device_Library/Class/CDC/Inc
        User/USB/STM32_USB_Device_Library/Class/CustomHID/Inc
        User/USB/STM32_USB_Device_Library/Class/DFU/Inc
        User/USB/STM32_USB_Device_Library/Class/HID/Inc
        User/USB/STM32_USB_Device_Library/Class/MSC/Inc
        User/USB/STM32_USB_Device_Library/Class/MSC_CDC

        # Other vendor libraries
        User/USB/STM32_TouchSensing_Library/inc

        # FreeRTOS
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3

        # Application
        User
        User/USB
        User/utils
        User/TinyFrame
        User/framework
        User/platform
        User/units/neopixel
        User/units/pin
        User/units/system
        Inc
)

add_executable(main ${SOURCE_FILES})
