#ifndef _RING_H_
#define _RING_H_
#include<stdbool.h>
#include "fsl_spi_master_driver.h"

void Kawhoosh();
void Wormhole(bool);
void DailingSequence();
void GlyphInit();
uint32_t calculatedBaudRate;
spi_master_state_t spiMasterState;
spi_master_user_config_t spiConfig;

#endif
