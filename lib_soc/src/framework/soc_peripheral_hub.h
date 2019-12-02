// Copyright (c) 2019, XMOS Ltd, All rights reserved

#ifndef SOC_PERIPHERAL_HUB_H_
#define SOC_PERIPHERAL_HUB_H_

#include <stdint.h>

#define SOC_PERIPHERAL_CHANNEL_COUNT 3
#define SOC_PERIPHERAL_FROM_DMA_CH   0
#define SOC_PERIPHERAL_TO_DMA_CH     1
#define SOC_PERIPHERAL_CONTROL_CH    2

#define SOC_PERIPHERAL_ISR_DMA_RX_DONE_BM 0x00000001
#define SOC_PERIPHERAL_ISR_DMA_TX_DONE_BM 0x00000002

#ifndef __XC__

#include "soc_dma_ring_buf.h"
#include "rtos_support.h"


struct soc_peripheral;
typedef struct soc_peripheral * soc_peripheral_t;

soc_peripheral_t soc_peripheral_register(
        chanend c[SOC_PERIPHERAL_CHANNEL_COUNT]);

void soc_peripheral_handler_register(
        soc_peripheral_t device,
        int core_id,
        void *app_data,
        rtos_irq_isr_t isr);

void *soc_peripheral_app_data(
        soc_peripheral_t device);

soc_dma_ring_buf_t *soc_peripheral_rx_dma_ring_buf(
        soc_peripheral_t device);

soc_dma_ring_buf_t *soc_peripheral_tx_dma_ring_buf(
        soc_peripheral_t device);

chanend soc_peripheral_ctrl_chanend(
        soc_peripheral_t device);

void soc_peripheral_hub_dma_request(void);

uint32_t soc_peripheral_interrupt_status(
        soc_peripheral_t device);

#endif // __XC__

#ifdef __XC__
extern "C" {
#endif //__XC__

#ifdef __XC__
#pragma select handler
#endif //__XC__
/**
 *
 */
void soc_peripheral_rx_dma_ready(
        chanend c);

uint16_t soc_peripheral_rx_dma_xfer(
        chanend c,
        void *data,
        uint16_t max_length);

void soc_peripheral_tx_dma_xfer(
        chanend c,
        void *data,
        uint16_t length);

void soc_peripheral_hub();

#ifdef __XC__
}
#endif //__XC__

#endif /* SOC_PERIPHERAL_HUB_H_ */