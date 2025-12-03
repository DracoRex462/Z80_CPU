cmake_minimum_required(VERSION 4.0)
project(Z80_CPU)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)
enable_testing()

add_executable(Z80_CPU
        main.cpp
        Z80.cpp
        Z80.h
        CPU/ALU.cpp
        CPU/ALU.h
        CPU/ControlUnit.cpp
        CPU/ControlUnit.h
        CPU/PC.h
        Hardware/Combinational/FullAdder.cpp
        Hardware/Combinational/FullAdder.h
        Hardware/Combinational/FullAdder8.cpp
        Hardware/Combinational/FullAdder8.h
        Hardware/Combinational/FullSubtractor.cpp
        Hardware/Combinational/FullSubtractor.h
        Hardware/Combinational/FullSubtractor8.cpp
        Hardware/Combinational/FullSubtractor8.h
        Hardware/Combinational/HalfAdder.cpp
        Hardware/Combinational/HalfAdder.h
        Hardware/Logic/AND.h
        Hardware/Logic/Bit.h
        Hardware/Logic/Gate.h
        Hardware/Logic/NOT.h
        Hardware/Logic/OR.h
        Hardware/Logic/XOR.h
        Memory/Memory.h
        Memory/Register.h
)
