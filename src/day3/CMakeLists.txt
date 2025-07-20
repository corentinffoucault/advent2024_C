
cmake_minimum_required(VERSION  3.10)


project(day3)


set(SRCS
    day3.cpp
    )
    
set(HEADERS
    day3.h
    )
    
add_library(day3 ${SRCS} ${HEADERS})

target_link_libraries(day3 days)
