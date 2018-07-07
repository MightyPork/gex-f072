//
// Created by MightyPork on 2018/07/07.
//

#include "platform.h"
#include "resources.h"

uint32_t plat_init_resources2(void)
{
    uint32_t rv = 0; // accumulate error codes

    // Free all present resources
    {
        rsc_free(NULL, R_ADC1);
//        rsc_free(NULL, R_CAN1);
//        rsc_free_range(NULL, R_COMP1, R_COMP2);
        rsc_free(NULL, R_DAC1);
//        rsc_free(NULL, R_HDMI_CEC);
        rsc_free(NULL, R_TSC);
        rsc_free_range(NULL, R_I2C1, R_I2C2);
//        rsc_free_range(NULL, R_I2S1, R_I2S2);
        rsc_free_range(NULL, R_SPI1, R_SPI2);
        rsc_free_range(NULL, R_TIM1, R_TIM3);
        rsc_free_range(NULL, R_TIM6, R_TIM7);
        rsc_free_range(NULL, R_TIM14, R_TIM17);
        rsc_free_range(NULL, R_USART1, R_USART4);
        rsc_free_range(NULL, R_DMA1_1, R_DMA1_7);

        rsc_free_range(NULL, R_PA0, R_PA15);
        rsc_free_range(NULL, R_PB0, R_PB15);
        rsc_free_range(NULL, R_PC0, R_PC15);
        rsc_free(NULL, R_PD2);
        rsc_free_range(NULL, R_PF0, R_PF1);
    }

    // Claim resources not available due to board layout or internal usage
    {
        // HAL timebase
        rv |= rsc_claim(&UNIT_SYSTEM, R_TIM17);
        // HSE crystal
        rv |= rsc_claim(&UNIT_SYSTEM, R_PF0);

#if PLAT_FULL_XTAL
        rv |= rsc_claim(&UNIT_SYSTEM, R_PF1); // - not used in BYPASS mode
#endif

        // SWD
//        rv |= rsc_claim(&UNIT_SYSTEM, R_PA13);
//        rv |= rsc_claim(&UNIT_SYSTEM, R_PA14);
        // USB
        rv |= rsc_claim(&UNIT_SYSTEM, R_PA11);
        rv |= rsc_claim(&UNIT_SYSTEM, R_PA12);

#if defined(GEX_PLAT_F072_ZERO)
        // unconnected pins
        rv |= rsc_claim_range(&UNIT_PLATFORM, R_PC0, R_PC1);
        rv |= rsc_claim_range(&UNIT_PLATFORM, R_PC4, R_PC9);
#endif
    }

    return rv;
}
