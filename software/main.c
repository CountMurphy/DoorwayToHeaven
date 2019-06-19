#include "fsl_os_abstraction.h"
#include "fsl_smc_hal.h"
#include "pins.h"
#include "ring.h"

int main()
{
    hardware_init();
    OSA_Init();
    ChevronInit();

    //main function taken care of in interrupt
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
