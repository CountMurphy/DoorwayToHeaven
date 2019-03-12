#include "pins.h"
#include "ring.h"

int main()
{
    hardware_init();
    GlyphInit();
    //check for button press 4 dmeo mode

    //random timer?

    //main function taken care of in interrupt
    for(;;)
    {
    }
    return 0;
}

//setup  interrupts
void PORTA_IRQHandler(void)
{
    Kawhoosh();
}
