/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"

int main() {

    const uint BUTTON = 14;
    const uint LED = 19;

    stdio_init_all();

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_down(BUTTON);

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    
    while (true) {
        if(gpio_get(BUTTON)) {
            gpio_xor_mask(1<<LED);
            sleep_ms(250);
        }
    }

}
