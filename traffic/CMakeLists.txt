add_executable(traffic
        traffic.c
        )

# pull in common dependencies
target_link_libraries(traffic pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(traffic 1)
pico_enable_stdio_uart(traffic 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(traffic)

# add url via pico_set_program_url
example_auto_set_url(traffic)
