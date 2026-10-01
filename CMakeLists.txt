cmake_minimum_required(VERSION 3.28)
project(TestLinuxCan)

set(CMAKE_CXX_STANDARD 26)

add_executable(TestLinuxCan main.cpp
        CanApplication/CanApp.cpp
        CanApplication/CanApp.h
        Drivers/CanBus.cpp
        Drivers/CanBus.h
        Drivers/SocketCan.cpp
        Drivers/SocketCan.h)

target_sources(TestLinuxCan PRIVATE
        third_party/libcanard/libcanard/canard.c
)

target_include_directories(TestLinuxCan PRIVATE
        third_party/libcanard/libcanard
        third_party/libcanard/lib/cavl2
)