
cmake_minimum_required(VERSION  3.10)

project(mazeSolver)

set(SRCS
    AMazeSolver.cpp
    MazeSolver.cpp
    MazeSolverV2.cpp
    spot.cpp
    )
    
set(HEADERS
    AMazeSolver.h
    MazeSolver.h
    MazeSolverV2.h
    spot.h
    )

add_library(mazeSolver ${SRCS} ${HEADERS})

target_link_libraries(mazeSolver Point2D)
