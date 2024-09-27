add_executable(temperature
        temperature.c
        )

# pull in common dependencies and additional i2c hardware support
target_link_libraries(temperature pico_stdlib hardware_i2c)

# enable usb output, disable uart output
pico_enable_stdio_usb(temperature 1)
pico_enable_stdio_uart(temperature 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(temperature)

# add url via pico_set_program_url
example_auto_set_url(temperature)

