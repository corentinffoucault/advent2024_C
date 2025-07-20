
cmake_minimum_required(VERSION  3.10)


project(day13)


set(SRCS
    day13.cpp
    Machine.cpp
    )
    
set(HEADERS
    day13.h
    Machine.h
    )
    
add_library(day13 ${SRCS} ${HEADERS})

target_link_libraries(day13 days Point2D)
