/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"

int main() {

    const uint LED_PIN_RED = 21;
    const uint LED_PIN_YELLOW = 20;
    const uint LED_PIN_GREEN = 19;

    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_YELLOW);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    
    while (true) {
        gpio_put(LED_PIN_GREEN, 0);
        gpio_put(LED_PIN_RED, 1);
        sleep_ms(500);
        gpio_put(LED_PIN_RED, 0);
        gpio_put(LED_PIN_YELLOW, 1);
        sleep_ms(500);
        gpio_put(LED_PIN_YELLOW, 0);
        gpio_put(LED_PIN_GREEN, 1);
        sleep_ms(500);
        printf("Hello, world!\n");
    }

}
