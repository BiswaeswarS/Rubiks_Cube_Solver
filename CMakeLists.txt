cmake_minimum_required(VERSION 3.25)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubiks_Cube_Solver main.cpp
        Representations/rubikscube1D.cpp
        Representations/rubikscube3D.cpp
        Representations/Generic_Rubiks_Cube.cpp
        Representations/Generic_Rubiks_Cube.h
)
