
cmake_minimum_required(VERSION  3.10)

project(computer)

set(SRCS
    ComputerMemory.cpp
    Computer.cpp
    Combo.cpp
    )
    
set(HEADERS
    ComputerMemory.h
    Computer.h
    Combo.h
    )

add_library(computer ${SRCS} ${HEADERS})

target_link_libraries(computer)
