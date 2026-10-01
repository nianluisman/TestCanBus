cmake_minimum_required(VERSION 3.28)
project(TestLinuxCan)

set(CMAKE_CXX_STANDARD 26)

add_executable(TestLinuxCan main.cpp
        CanApplication/CanApp.cpp
        CanApplication/CanApp.h
        Drivers/CanBus.cpp
        Drivers/CanBus.h)
