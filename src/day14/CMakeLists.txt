
cmake_minimum_required(VERSION  3.10)


project(day14)


set(SRCS
    day14.cpp
    Robot.cpp
    )
    
set(HEADERS
    day14.h
    Robot.h
    )
    
add_library(day14 ${SRCS} ${HEADERS})

target_link_libraries(day14 days Point2D)
