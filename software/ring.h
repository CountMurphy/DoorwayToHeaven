#ifndef _RING_H_
#define _RING_H_
#include<stdbool.h>
#include "fsl_spi_master_driver.h"

typedef struct{
    volatile uint8_t Reg;
    volatile uint8_t Chevron;
} tRegInfo;

void Kawhoosh();
void Wormhole(bool);
void DailingSequence();
void ChevronInit();
uint32_t calculatedBaudRate;
spi_master_state_t spiMasterState;
spi_master_user_config_t spiConfig;
void ClockWise(uint8_t mask[5], tRegInfo startByte,tRegInfo endByte);
void CounterClockWise(uint8_t mask[5],tRegInfo startByte, tRegInfo endByte);
void DailThis(uint8_t digits[5]);
uint8_t* Mask(uint8_t digits[5],uint8_t mask[5]);

#endif
