add_executable(lcd_1602_i2c
        lcd_1602_i2c.c
        )

# pull in common dependencies and additional i2c hardware support
target_link_libraries(lcd_1602_i2c pico_stdlib hardware_i2c)

# enable usb output, disable uart output
pico_enable_stdio_usb(lcd_1602_i2c 1)
pico_enable_stdio_uart(lcd_1602_i2c 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(lcd_1602_i2c)

# add url via pico_set_program_url
example_auto_set_url(lcd_1602_i2c)
