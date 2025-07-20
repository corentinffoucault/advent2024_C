
cmake_minimum_required(VERSION  3.10)


project(day10)


set(SRCS
    day10.cpp
    Topographic.cpp
    )
    
set(HEADERS
    day10.h
    Topographic.h
    )
    
add_library(day10 ${SRCS} ${HEADERS})

target_link_libraries(day10 days Point2D)
