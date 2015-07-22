/* Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Interrupt based USART RX driver for STM32 */

#include "usart.h"

#include "atomic.h"
#include "common.h"
#include "queue.h"
#include "registers.h"

static void usart_rx_init(struct usart_config const *config)
{
	intptr_t base = config->hw->base;

	STM32_USART_CR1(base) |= STM32_USART_CR1_RXNEIE;
	STM32_USART_CR1(base) |= STM32_USART_CR1_RE;
}

static void usart_rx_interrupt_handler(struct usart_config const *config)
{
	intptr_t base = config->hw->base;
	uint8_t  byte;

	if (!(STM32_USART_SR(base) & STM32_USART_SR_RXNE))
		return;

	byte = STM32_USART_RDR(base);

	if (!queue_add_unit(config->producer.queue, &byte))
		atomic_add(&config->state->rx_dropped, 1);
}

struct usart_rx const usart_rx_interrupt = {
	.producer_ops = {
		/*
		 * Nothing to do here, we either had enough space in the queue
		 * when a character came in or we dropped it already.
		 */
		.read = NULL,
	},

	.init      = usart_rx_init,
	.interrupt = usart_rx_interrupt_handler,
};
