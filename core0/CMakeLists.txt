add_executable(core0
    main.cpp
)

pico_set_program_name(core0 "core0")
pico_set_program_version(core0 "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(core0 0)
pico_enable_stdio_usb(core0 1)

# Add the standard library to the build
target_link_libraries(core0
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(core0 PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(core0 
        hardware_spi
        hardware_i2c
        hardware_dma
        )

pico_add_extra_outputs(core0)

message( "Core0 build type: ${CMAKE_BUILD_TYPE}")