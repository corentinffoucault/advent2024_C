
cmake_minimum_required(VERSION  3.10)


project(day8)


set(SRCS
    day8.cpp
    )
    
set(HEADERS
    day8.h
    )
    
add_library(day8 ${SRCS} ${HEADERS})

target_link_libraries(day8 days Point2D)
