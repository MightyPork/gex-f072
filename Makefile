###################################################################
# GEX F072 makefile
###################################################################


# Defaults - set in build.mk
GEX_PLAT          = UNSET
DISABLE_DEBUG     = 0
DISABLE_MSC       = 0
CDC_LOOPBACK_TEST = 0
DEBUG             = 1

PLAT_C_DIRS =
PLAT_C_FILES =
PLAT_C_INCLUDES =
PLAT_C_FLAGS =

PLAT_AS_DIRS =
PLAT_AS_FILES =
PLAT_AS_INCLUDES =
PLAT_AS_FLAGS =

# User params can be set here
include build.mk


######################################

PLAT_C_DIRS +=

# C sources
PLAT_C_FILES +=  \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_adc.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_comp.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_crc.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_crs.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dac.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_i2c.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rtc.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_spi.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_tim.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usart.c \
    Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.c \
    Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c \
    Src/stm32f0xx_hal_msp.c \
    Src/system_stm32f0xx.c

PLAT_C_INCLUDES += \
    -IDrivers/STM32F0xx_HAL_Driver/Inc \
    -IDrivers/STM32F0xx_HAL_Driver/Inc/Legacy \
    -IMiddlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 \
    -IDrivers/CMSIS/Device/ST/STM32F0xx/Include

PLAT_C_FLAGS += \
    -DSTM32F072xB \
    -DARM_MATH_CM0PLUS
    
##############################################

PLAT_AS_DIRS +=

PLAT_AS_FILES += \
    startup_stm32f072xb.s

PLAT_AS_INCLUDES +=

PLAT_AS_FLAGS +=

##############################################

# CPU flags
PLAT_CPU = -mcpu=cortex-m0plus

# FPU flags
PLAT_FLOAT-ABI =

# link script
PLAT_LDSCRIPT = STM32F072RBTx_FLASH.ld

##############################################

include GexCore/gex.mk

# *** EOF ***
