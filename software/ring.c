#include "fsl_smc_hal.h"
#include "fsl_os_abstraction.h"
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

    rc = SPI_DRV_MasterTransferBlocking(0, NULL, tx, rx, count, 50);
    if (rc != kStatus_SPI_Success) {
        return rc;
    }
    int i, timeout = (count + 127) / 128 + 1;
    for (i = 0; i < timeout; ++i) {
        rc = SPI_DRV_MasterGetTransferStatus(0, NULL);
        if (rc == kStatus_SPI_Success) {
            return rc;
        }
    }
    return rc;
}


void ChevronInit()
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
        gpio_output_pin_user_config_t rings[7]= {ring6,ring5,ring4,ring3,ring2,ring1,ring0};
        uint8_t onAnimation[17][2]={
            {0,1},
            {1,1},
            {0,0},
            {1,0},
            {2,1},
            {5,1},
            {5,0},
            {2,0},
            {3,1},
            {6,1},
            {3,0},
            {4,1},
            {3,1},
            {5,1},
            {2,1},
            {0,1},
            {1,1}
        };
    
        uint8_t offAnimation[7]= {
            0,
            1,
            2,
            3,
            5,
            4,
            6
        };
    
        uint32_t delay=50;
        for(int i=0;i<(isOn?17:7);i++)
        {
            if(isOn)
            {
                if(i==12)
                {
                    OSA_TimeDelay(800);
                    delay=100;
                }
                GPIO_DRV_WritePinOutput(rings[onAnimation[i][0]].pinName,onAnimation[i][1]);
                if(i!=16)
                    i++;
                GPIO_DRV_WritePinOutput(rings[onAnimation[i][0]].pinName,onAnimation[i][1]);
                OSA_TimeDelay(delay);
            }else{
                GPIO_DRV_WritePinOutput(rings[offAnimation[i]].pinName,0);
                OSA_TimeDelay(delay);
            }
    
        }

}


void DailingSequence()
{
    uint8_t skip[5]={0x00,0x00,0x00,0x00,0x00};
    uint8_t home[5]={0x00,0x00,0x00,0x00,0x80};
    uint8_t ab1[5]={0x00,0x08,0x00,0x00,0x00};
    uint8_t ab2[5]={0x00,0x08,0x00,0x20,0x00};
    uint8_t ab3[5]={0x00,0x08,0x20,0x20,0x00};
    uint8_t ab4[5]={0x00,0x09,0x20,0x20,0x00};
    uint8_t ab5[5]={0x00,0x09,0x24,0x20,0x00};
    uint8_t ab6[5]={0x00,0x49,0x24,0x20,0x00};

    tRegInfo startByte;
    startByte.Reg=0;

    tRegInfo endByte;
    endByte.Reg=4;
    endByte.Chevron=0x08;


    ClockWise(skip,startByte, endByte);

    endByte.Reg=1;
    endByte.Chevron=0x20;
    startByte.Reg=4;
    startByte.Chevron=0x08;
    CounterClockWise(ab1,startByte, endByte);

    startByte.Reg=1;
    startByte.Chevron=0x20;
    endByte.Reg=2;
    endByte.Chevron=0x20;
    ClockWise(ab2,startByte,endByte);

    //must call counter twice as first loop hits home and completes
    startByte.Reg=2;
    startByte.Chevron=0x20;
    endByte.Reg=4;
    endByte.Chevron=0x01;
    CounterClockWise(ab3,startByte,endByte);
    DailThis(Mask(home,ab3));
    startByte.Reg=1;
    startByte.Chevron=0x40;
    CounterClockWise(ab3,startByte,endByte);

    startByte.Reg=4;
    startByte.Chevron=0x01;
    endByte.Reg=5;
    endByte.Chevron=0x40;
    ClockWise(ab4,startByte,endByte);
    OSA_TimeDelay(100);
    DailThis(Mask(home,ab4));
    OSA_TimeDelay(100);
    startByte.Reg=1;
    startByte.Chevron=0x1;
    endByte.Reg=2;
    endByte.Chevron=0x04;
    ClockWise(ab4,startByte,endByte);

    startByte.Reg=2;
    startByte.Chevron=0x04;
    endByte.Reg=0;
    endByte.Chevron=0x20;
    CounterClockWise(ab5,startByte,endByte);
    DailThis(Mask(home,ab5));
    startByte.Reg=1;
    startByte.Chevron=0x40;
    endByte.Reg=4;
    endByte.Chevron=0x40;
    CounterClockWise(ab5,startByte,endByte);

    startByte.Reg=4;
    startByte.Chevron=0x40;
    ClockWise(ab6,startByte,endByte);
}

void CounterClockWise(uint8_t mask[5], tRegInfo startByte, tRegInfo endByte)
{
    uint8_t seg1=startByte.Reg==0?0x80:0x00;
    uint8_t seg2=0x00;
    uint8_t seg3=0x00;
    uint8_t seg4=0x00;
    uint8_t seg5=0x00;
    uint8_t checkByte=0x00;;
    int newstart=0;
    OSA_TimeDelay(100);
    switch(startByte.Reg)
    {
        case 1:
            seg1=startByte.Chevron;
            break;
        case 4:
            seg5=startByte.Chevron;
            if(startByte.Chevron==0x08)
                newstart=5;
            break;
        case 2:
            seg3=startByte.Chevron;
            break;
    }

    //technically reg 1 has at least 1 pin before home
    //this destroys loop logic
    uint8_t loopValue=startByte.Reg;
    if(startByte.Reg==1)
    {
        loopValue=5;
    }
    for(volatile int reg=loopValue;reg>=1;reg--)
    {

        for(int i=newstart;i<8;i++)
        {
            uint8_t digits[5]={seg4,seg5,seg3,seg2,seg1};
            
            if(!isNullCheck(digits))
                DailThis(Mask(digits,mask));
            else
                continue;
            switch(endByte.Reg)
            {
                case 1:
                    checkByte=seg2;
                    break;
                case 4:
                case 5:
                    checkByte=seg5;
                    break;
            }
            if(reg==endByte.Reg && checkByte==endByte.Chevron)
            {
                return;
            }
            switch(reg)
            {
                case 1:
                    seg2=seg2>>1;
                    break;
                case 2:
                    seg3=seg3>>1;
                    break;
                case 3:
                    seg4=seg4>>1;
                    break;
                case 4:
                    if(seg5==0x01)
                    {
                        seg5=0x80;
                    }
                    else
                    {
                        seg5=seg5>>1;
                    }
                    break;
                case 5:
                    seg1=seg1>>1;
                    break;
            }
            OSA_TimeDelay(100);
        }
        newstart=0;
        switch(reg)
        {
            case 1:
                seg2=0x00;
                seg1=0x80;
                break;
            case 2:
                seg3=0x00;
                seg2=0x80;
                break;
            case 3:
                seg4=0x00;
                seg3=0x80;
                break;
            case 4:
                seg5=0x00;
                seg4=0x80;
                break;
            case 5:
                seg5=0x01;
                break;
        }
    }
}

void ClockWise(uint8_t mask[5],tRegInfo startByte, tRegInfo endByte)
{
    uint8_t seg1=0x00;
    uint8_t seg2=0x00;
    uint8_t seg3=0x00;
    uint8_t seg4=0x00;
    uint8_t seg5=0x00;
    uint8_t checkByte=0x00;
    volatile int newstart=0;
    if(startByte.Reg==0)
    {
        uint8_t starting[5]={0x00,0x00,0x00,0x00,0x80};
        DailThis(starting);
        OSA_TimeDelay(500);
        seg2=0x01;
    }
    else
    {
        OSA_TimeDelay(100);
    }
    switch(startByte.Reg)
    {
        case 1:
            seg2=startByte.Chevron;
            if(startByte.Chevron==0x20)
                newstart=1;
            break;
        case 5:
            seg4=startByte.Chevron;
            break;
    }
    for(int reg=startByte.Reg==0?1:startByte.Reg;reg<=5;reg++)
    {

        for(int i=newstart;i<8;i++)
        {
            uint8_t digits[5]={seg4,seg5,seg3,seg2,seg1};
            if(!isNullCheck(digits))
                DailThis(Mask(digits,mask));
            else
                continue;
            switch(endByte.Reg)
            {
                case 2:
                    checkByte=seg3;
                    break;
                case 3:
                    checkByte=seg4;
                    break;
                case 4:
                    checkByte=seg5;
                    break;
                case 5:
                    checkByte=seg1;
                    break;
            }
            if(reg==endByte.Reg && checkByte==endByte.Chevron)
            {
                return;
            }
            switch(reg)
            {
                case 1:
                    seg2=seg2<<1;
                    if(seg2==0x00)
                        i=8;
                    break;
                case 2:
                    seg3=seg3<<1;
                    if(seg3==0x00)
                        i=8;
                    break;
                case 3:
                    seg4=seg4<<1;
                    if(seg4==0x00)
                        i=8;
                    break;
                case 4:
                    if(seg5==0x80)
                    {
                        seg5=0x1;
                    }
                    else
                    {
                        seg5=seg5<<1;
                    }
                    if(seg5==0x00)
                        i=8;
                    break;
                case 5:
                    seg1=seg1<<1;
                    if(seg1==0x00)
                        i=8;
                    break;
            }
            OSA_TimeDelay(100);
        }
        newstart=0;
        switch(reg)
        {
            case 1:
                seg2=0x00;
                seg3=0x01;
                break;
            case 2:
                seg3=0x00;
                seg4=0x01;
                break;
            case 3:
                seg4=0x00;
                seg5=0x02;
                break;
            case 4:
                seg5=0x00;
                seg1=0x01;
                break;
        }
    }
}

void DailThis(uint8_t digits[5])
{
    SPI_Transfer(digits,NULL,5);
    GPIO_DRV_WritePinOutput(Latch.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,0);
}

uint8_t* Mask(uint8_t digits[5],uint8_t mask[5])
{
    for(int i=0;i<5;i++)
    {
        digits[i]=digits[i]|mask[i];
    }
    return digits;
}

bool isNullCheck(uint8_t digits[5])
{
    bool isNull=true;
    for(int i=0;i<5;i++)
    {
        if(digits[i]!=0x00)
        {
            isNull=false;
            break;
        }
    }
    return isNull;
}

void test()
{
    //test sequence
    
    uint8_t all[5]={0xff,0xff,0xff,0xff,0xff};
    SPI_Transfer(all,NULL,5);
    GPIO_DRV_WritePinOutput(Latch.pinName,1);
    GPIO_DRV_WritePinOutput(Latch.pinName,0);
    OSA_TimeDelay(1000);

    GPIO_DRV_WritePinOutput(ring0.pinName,1);
    GPIO_DRV_WritePinOutput(ring1.pinName,1);
    GPIO_DRV_WritePinOutput(ring2.pinName,1);
    GPIO_DRV_WritePinOutput(ring3.pinName,1);
    GPIO_DRV_WritePinOutput(ring4.pinName,1);
    GPIO_DRV_WritePinOutput(ring5.pinName,1);
    GPIO_DRV_WritePinOutput(ring6.pinName,1);
    OSA_TimeDelay(1000);
    GPIO_DRV_WritePinOutput(ring0.pinName,0);
    GPIO_DRV_WritePinOutput(ring1.pinName,0);
    GPIO_DRV_WritePinOutput(ring2.pinName,0);
    GPIO_DRV_WritePinOutput(ring3.pinName,0);
    GPIO_DRV_WritePinOutput(ring4.pinName,0);
    GPIO_DRV_WritePinOutput(ring5.pinName,0);
    GPIO_DRV_WritePinOutput(ring6.pinName,0);
}
