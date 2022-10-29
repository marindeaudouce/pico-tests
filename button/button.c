/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint BUTTON = 14;
const uint LED = 19;

void gpio_irqHandler(uint gpio, uint32_t events) {
    gpio_xor_mask(1<<LED);
    printf("Button pressed !\n");
}

int main() {
    
    stdio_init_all();

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_down(BUTTON);

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &gpio_irqHandler);
    
    while (true);

}
