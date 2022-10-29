add_executable(button
        button.c
        )

# pull in common dependencies
target_link_libraries(button pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(button 1)
pico_enable_stdio_uart(button 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(button)

# add url via pico_set_program_url
example_auto_set_url(button)
