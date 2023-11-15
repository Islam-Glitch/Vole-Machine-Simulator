cmake_minimum_required(VERSION 3.26)
project(Vole_Machine_Simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Vole_Machine_Simulator
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h
        VoleMachine.cpp
        VoleMachine.h
        VoleMachineQT.cpp)
