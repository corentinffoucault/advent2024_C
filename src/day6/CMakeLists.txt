
cmake_minimum_required(VERSION  3.10)


project(day6)


set(SRCS
    day6.cpp
    )
    
set(HEADERS
    day6.h
    )
    
add_library(day6 ${SRCS} ${HEADERS})

target_link_libraries(day6 days Point2D)
