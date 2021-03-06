// Copyright (c) 2019, XMOS Ltd, All rights reserved

#ifndef GPIO_DEV_H_
#define GPIO_DEV_H_

#if __soc_conf_h_exists__
#include "soc_conf.h"
#else
#warning soc_conf.h not found
#endif

#include "gpio_dev_conf_defaults.h"
#include "gpio_dev_ctrl.h"
#include "gpio_port_map.h"

#ifdef __XC__
extern "C" {
#endif //__XC__

void gpio_dev(
        soc_peripheral_t peripheral,
        chanend data_to_dma_c,
        chanend data_from_dma_c,
        chanend ctrl_c,
        chanend irq_c);

#ifdef __XC__
}
#endif //__XC__

#endif /* GPIO_DEV_H_ */
