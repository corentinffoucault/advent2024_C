
cmake_minimum_required(VERSION  3.10)


project(day5)


set(SRCS
    day5.cpp
    )
    
set(HEADERS
    day5.h
    )
    
add_library(day5 ${SRCS} ${HEADERS})

target_link_libraries(day5 days)
