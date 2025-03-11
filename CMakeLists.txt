cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17) 

project(advent2024)

add_executable(adventOfCode_2024 adventOfCode_2024.cpp src/day1/day1.cpp)

target_include_directories( adventOfCode_2024 PUBLIC day/day1 ) 
