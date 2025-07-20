
cmake_minimum_required(VERSION  3.10)


project(day11)


set(SRCS
    day11.cpp
    )
    
set(HEADERS
    day11.h
    )
    
add_library(day11 ${SRCS} ${HEADERS})

target_link_libraries(day11 days libPerso)
