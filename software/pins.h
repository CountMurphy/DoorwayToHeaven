#ifndef _PINS_H_
#define _PINS_H_
#include "fsl_os_abstraction.h"
#include "fsl_i2c_hal.h"
#include "fsl_i2c_master_driver.h"
#include "fsl_port_hal.h"
#include "fsl_clock_manager.h"
#include "fsl_gpio_driver.h"


void hardware_init();

/*##################Switch#############################*/
static const gpio_input_pin_user_config_t ActivateSwitch={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,18)
};


/*##################SPI SHIT#############################*/
static const gpio_output_pin_user_config_t Reset={
    .pinName=GPIO_MAKE_PIN(GPIOD_IDX,3),
    .config.outputLogic=1
};
static const gpio_output_pin_user_config_t Latch={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,12),
    .config.outputLogic=0
};
static const gpio_output_pin_user_config_t Enable={
    .pinName=GPIO_MAKE_PIN(GPIOC_IDX,9),
    .config.outputLogic=0
};
/*##################Lights#############################*/

static const gpio_output_pin_user_config_t ring0={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,1),
    .config.outputLogic=0
};
static const gpio_output_pin_user_config_t ring1={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,2),
    .config.outputLogic=0
};

static const gpio_output_pin_user_config_t ring2={
    .pinName=GPIO_MAKE_PIN(GPIOB_IDX,19),
    .config.outputLogic=0
};


static const gpio_output_pin_user_config_t ring3={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,5),
    .config.outputLogic=0
};

static const gpio_output_pin_user_config_t ring4={
    .pinName=GPIO_MAKE_PIN(GPIOC_IDX,2),
    .config.outputLogic=0
};

static const gpio_output_pin_user_config_t ring5={
    .pinName=GPIO_MAKE_PIN(GPIOC_IDX,0),
    .config.outputLogic=0
};

static const gpio_output_pin_user_config_t ring6={
    .pinName=GPIO_MAKE_PIN(GPIOA_IDX,19),
    .config.outputLogic=0
};
#endif
