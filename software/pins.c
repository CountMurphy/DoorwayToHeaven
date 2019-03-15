#include "pins.h"

void hardware_init()
{
    CLOCK_SYS_EnablePortClock(PORTA_IDX);
    CLOCK_SYS_EnablePortClock(PORTC_IDX);
    CLOCK_SYS_EnablePortClock(PORTD_IDX);
    CLOCK_SYS_EnablePortClock(PORTE_IDX);


    //Set lights to GPIO
    PORT_HAL_SetMuxMode(PORTA,1u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTA,2u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTB,19u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTA,5u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTC,2u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTC,0u,kPortMuxAsGpio);
    PORT_HAL_SetMuxMode(PORTA,19u,kPortMuxAsGpio);

    //Set input switch
    PORT_HAL_SetMuxMode(PORTA,18u,kPortMuxAsGpio);

    //set SPI
    PORT_HAL_SetMuxMode(PORTD,1u,kPortMuxAlt2); //clock
    PORT_HAL_SetMuxMode(PORTD,2u,kPortMuxAlt2); //data
    //SPI Reset
    PORT_HAL_SetMuxMode(PORTD,3u,kPortMuxAsGpio);
    //SPI Latch
    PORT_HAL_SetMuxMode(PORTA,12u,kPortMuxAsGpio);
    //SPI ENABLE
    PORT_HAL_SetMuxMode(PORTC,9u,kPortMuxAsGpio);

    GPIO_DRV_InputPinInit(&ActivateSwitch);
    //GPIO_DRV_OutputPinInit(&ring0);
    //GPIO_DRV_OutputPinInit(&ring1);
    //GPIO_DRV_OutputPinInit(&ring2);
    //GPIO_DRV_OutputPinInit(&ring3);
    //GPIO_DRV_OutputPinInit(&ring4);
    //GPIO_DRV_OutputPinInit(&ring5);
    //GPIO_DRV_OutputPinInit(&ring6);
    //spi
    GPIO_DRV_OutputPinInit(&Reset);
    GPIO_DRV_OutputPinInit(&Latch);
    GPIO_DRV_OutputPinInit(&Enable);

}

