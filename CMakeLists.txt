cmake_minimum_required(VERSION 3.26)
project(ASTP_BF_B_B_DP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ASTP_BF_B_B_DP
        Brute_force.cpp
        Brute_force.h
        Graph.cpp
        Graph.h
        main.cpp
        Menu.cpp
        Menu.h
        Time_measure.cpp
        Time_measure.h
        Write_to_csv.cpp
        Write_to_csv.h
        Data_generator.h
        Data_generator.cpp
        Dynamic_programming.h
        Dynamic_programming.cpp)
