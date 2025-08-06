
cmake_minimum_required(VERSION  3.10)

project(mazeSolver20)

set(SRCS
    MazeSolver20.cpp
    CheatingMaze.cpp
    )
    
set(HEADERS
    MazeSolver20.h
    CheatingMaze.h
    )

add_library(mazeSolver20 ${SRCS} ${HEADERS})

target_link_libraries(mazeSolver20 Point2D)
