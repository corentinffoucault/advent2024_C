cmake_minimum_required(VERSION 3.10)

# Add additional compiler flags
# Built-ins:
#   - CMAKE_CXX_FLAGS_DEBUG = -g
#   - CMAKE_CXX_FLAGS_RELEASE = -O3 -NDEBUG
set(CMAKE_CXX_FLAGS "-Wall /EHs")
set(CMAKE_CXX_STANDARD 20) 

project(advent2024)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# On inclut notre biblioth�que dans le processus de CMake
add_subdirectory(src)
add_subdirectory(lib)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    adventOfCode_2024.cpp
    )
    
# Notre ex�cutable
add_executable(main ${SRCS})

# Et pour que l'ex�cutable fonctionne, il faut lui indiquer la biblioth�que dont il d�pend
target_link_libraries(main libPerso day1 day2 day3 day4 day5 day6 day7 day8 day9 day10 day11 day12 day13 day14)
