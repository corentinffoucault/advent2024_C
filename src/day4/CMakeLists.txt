
cmake_minimum_required(VERSION  3.10)


project(day4)


set(SRCS
    day4.cpp
    )
    
set(HEADERS
    day4.h
    )
    
add_library(day4 ${SRCS} ${HEADERS})

target_link_libraries(day4 days)
