
cmake_minimum_required(VERSION  3.10)


project(day15)


set(SRCS
    day15.cpp
    )
    
set(HEADERS
    day15.h
    )

add_library(day15 ${SRCS} ${HEADERS})
    
add_subdirectory(sokoban)

target_link_libraries(day15 days Point2D sokoban)
