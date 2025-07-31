
cmake_minimum_required(VERSION  3.10)

project(mazeSolver18)

set(SRCS
    MazeSolver18.cpp
    MazeSolver18V2.cpp
    )
    
set(HEADERS
    MazeSolver18.h
    MazeSolver18V2.h
    )

add_library(mazeSolver18 ${SRCS} ${HEADERS})

target_link_libraries(mazeSolver18 Point2D)
