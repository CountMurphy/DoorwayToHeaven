#include<stdbool.h>
#include "ring.h"
#include "pins.h"


spi_master_user_config_t spiConfig =
{
    .bitsPerSec = 4000000, /* 4 MHz */
    .polarity = kSpiClockPolarity_ActiveHigh,
    .phase = kSpiClockPhase_FirstEdge,
    .direction = kSpiMsbFirst,
    .bitCount = kSpi8BitMode,
};

static spi_status_t SPI_Transfer(const uint8_t *tx, uint8_t *rx, size_t count)
{
    spi_status_t rc;

    rc = SPI_DRV_MasterTransfer(1, NULL, tx, rx, count);
    if (rc != kStatus_SPI_Success) {
        return rc;
    }
    int i, timeout = (count + 127) / 128 + 1;
    for (i = 0; i < timeout; ++i) {
        rc = SPI_DRV_MasterGetTransferStatus(1, NULL);
        if (rc == kStatus_SPI_Success) {
            return rc;
        }
    }
    return rc;
}


void GlyphInit()
{
    SPI_DRV_MasterInit(0, &spiMasterState);
    SPI_DRV_MasterConfigureBus(0,&spiConfig,&calculatedBaudRate);
}

void Kawhoosh()
{
    Wormhole(true);
    OSA_TimeDelay(5000);
    Wormhole(false);
}

void Wormhole(bool isOn)
{
    gpio_output_pin_user_config_t rings[7]= {ring0,ring1,ring2,ring3,ring4,ring5,ring6};

    uint8_t onAnimation[19][2]={
        {0,1},
        {0,0},
        {1,1},
        {1,0},
        {2,1},
        {2,0},
        {3,1},
        {3,0},
        {4,1},
        {4,0},
        {5,1},
        {5,0},
        {6,1},
        {5,1},
        {4,1},
        {3,1},
        {2,1},
        {1,1},
        {0,1}
    };
    uint8_t offAnimation[7][2]={
        {0,0},
        {1,0},
        {2,0},
        {3,0},
        {4,0},
        {5,0},
        {6,0}
    };

    for(int i=0;i<(isOn?19:7);i++)
    {
        if(isOn)
        {
            GPIO_DRV_WritePinOutput(rings[onAnimation[i][0]].pinName,onAnimation[i][1]);
            OSA_TimeDelay(500);
        }else{
            GPIO_DRV_WritePinOutput(rings[onAnimation[i][0]].pinName,offAnimation[i][1]);
            OSA_TimeDelay(500);
        }

    }

}


void DailingSquence()
{
    uint8_t lighAll=0xFF;
    for(int i=0;i<5;i++)
    {
        SPI_Transfer(&lighAll,NULL,8);
    }
}
