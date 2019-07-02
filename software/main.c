#include "fsl_os_abstraction.h"
#include "fsl_smc_hal.h"
#include "pins.h"
#include "ring.h"


/* Configuration for enter VLPR mode. Core clock = 4MHz. */
static const clock_manager_user_config_t g_defaultClockConfigVlpr = {   
    .mcgliteConfig =
    {    
        .mcglite_mode       = kMcgliteModeLirc8M,   // Work in LIRC_8M mode.
        .irclkEnable        = true,  // MCGIRCLK enable.
        .irclkEnableInStop  = false, // MCGIRCLK disable in STOP mode.
        .ircs               = kMcgliteLircSel8M, // Select LIRC_8M.
        .fcrdiv             = kMcgliteLircDivBy1,    // FCRDIV is 0.
        .lircDiv2           = kMcgliteLircDivBy1,    // LIRC_DIV2 is 0.
        .hircEnableInNotHircMode         = false, // HIRC disable.
    },
    .simConfig =
    {    
        .er32kSrc  = kClockEr32kSrcOsc0,   // ERCLK32K selection, use OSC.
        .outdiv1   = 1U, // divide by 2, core clock = 8 MHz / 2
        .outdiv4   = 3U, // divide by 4, bus clock = 4 MHz / 4
    },
    .oscerConfig =
    {   
        .enable       = false, // OSCERCLK disable.
        .enableInStop = false, // OSCERCLK disable in STOP mode.
    }
};


int main()
{
    hardware_init();
    OSA_Init();
    ChevronInit();


    CLOCK_SYS_SetConfiguration(&g_defaultClockConfigVlpr);
    //main function taken care of in interrupt
    GPIO_DRV_WritePinOutput(Reset.pinName,0);
    GPIO_DRV_WritePinOutput(Reset.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,0);
    test();
    GPIO_DRV_WritePinOutput(Reset.pinName,0);
    GPIO_DRV_WritePinOutput(Reset.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,0);
    while(1)
    {
        if(!GPIO_DRV_ReadPinInput(ActivateSwitch.pinName))
        {
            GPIO_DRV_WritePinOutput(Reset.pinName,0);
            GPIO_DRV_WritePinOutput(Reset.pinName,1);
            GPIO_DRV_WritePinOutput(Latch.pinName,1);
            GPIO_DRV_WritePinOutput(Latch.pinName,0);
            DailingSequence();
            OSA_TimeDelay(225);
            GPIO_DRV_WritePinOutput(Reset.pinName,0);
            GPIO_DRV_WritePinOutput(Reset.pinName,1);
            GPIO_DRV_WritePinOutput(Latch.pinName,1);
            GPIO_DRV_WritePinOutput(Latch.pinName,0);

            Kawhoosh();
        }
    }
    return 0;
}

//setup  interrupts
//void PORTA_IRQHandler(void)
//{
//}
