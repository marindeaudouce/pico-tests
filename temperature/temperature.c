#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define CONV_FORMULA_DIV 65536
#define CONV_FORMULA_MUL 175
#define CONV_FORMULA_OFF -45

void clear_rx(uint8_t* rxdata, uint8_t len){
    for(uint8_t idx = 0; idx < len; idx++){
        rxdata[idx] = 0;
    }
}

float compute_temp(uint16_t rxdata){
    return CONV_FORMULA_MUL*((float)(rxdata)/CONV_FORMULA_DIV) + CONV_FORMULA_OFF;
}

int main() {
    stdio_init_all();

    // Use I2C0 on the default SDA and SCL pins (GP4, GP5 on a Pico)
    i2c_init(i2c_default, 100 * 1000); // baudreate is 100KHz 
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Try to read the ID
    uint8_t addr = 0x70;
    int ret = 0;
    // RX/TX buffers
    uint8_t rxdata[2];
    clear_rx(rxdata, 2);
    uint8_t buf[2]; // Read ID command  
    buf[0] = 0x7C; // MSB first
    buf[1] = 0xA2;

    while (true) {
        ret = i2c_write_blocking(i2c_default, addr, buf, 2, false);
        if(ret < 0){
            printf("Write issue %d\n", ret);
        }
        ret = i2c_read_blocking(i2c_default, addr, rxdata, 2, false);
        if(ret < 0){
            printf("Read issue %d\n", ret);
        }
        uint16_t msb = (uint16_t)rxdata[0] << 8;
        uint16_t full_data = (uint16_t)(msb + rxdata[1]);
        float conv_data = compute_temp(full_data);
        printf("Temperature is %f\n", conv_data);
        clear_rx(rxdata, 2);
        sleep_ms(10000);
    }
}