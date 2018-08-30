set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.10)
project(STM32_Explorer)

# Actual compile command
add_custom_target(Main COMMAND make -j -C ${Insouled_ChibiOS_CPP_SOURCE_DIR}/dev)

# make clean
add_custom_target(clean_make COMMAND make clean -C ${Insouled_ChibiOS_CPP_SOURCE_DIR}/dev)

# Our source files
set(DEVCPPSRC
        dev/main.cpp dev/led.cpp dev/led.hpp)

# Our include directories
include_directories(dev)


# This target is used to make CLion IDE work properly
# There is no need to edit them
include(os/ch.cmake)
add_library(useless_cmake_target ${DEVCPPSRC} ${ALLCSRC})