cmake_minimum_required(VERSION 3.25)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubiks_Cube_Solver main.cpp Generic_Rubiks_Cube.cpp Generic_Rubiks_Cube.h
        1drepresentation.cpp)
