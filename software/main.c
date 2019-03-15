#include "fsl_os_abstraction.h"
#include "fsl_smc_hal.h"
#include "pins.h"
#include "ring.h"

int main()
{
    hardware_init();
    OSA_Init();
    GlyphInit();
    //check for button press 4 dmeo mode

    //random timer?

    GPIO_DRV_WritePinOutput(Reset.pinName,0);
    GPIO_DRV_WritePinOutput(Reset.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,0);
    DailingSequence();
    //Kawhoosh();
    //main function taken care of in interrupt
    for(;;)
    {
    }
    return 0;
}

//setup  interrupts
//void PORTA_IRQHandler(void)
//{
//    Kawhoosh();
//}
