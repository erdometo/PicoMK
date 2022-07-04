# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/pico-sdk")
set(FREERTOS_KERNEL_PATH, "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Kernel")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
include(FreeRTOS_Kernel_import.cmake)

project(firmware C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(firmware main.cc layout.cc)

pico_set_program_name(firmware "Pico Keyboard Firmware")
pico_set_program_version(firmware "0.1")

pico_enable_stdio_uart(firmware 0)
pico_enable_stdio_usb(firmware 0)

# Add the standard library to the build
target_link_libraries(firmware pico_stdlib tinyusb_device FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)

# Add any user requested libraries
target_link_libraries(firmware
        hardware_i2c
        hardware_watchdog
        hardware_clocks
        )

target_include_directories(firmware PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )

pico_add_extra_outputs(firmware)
