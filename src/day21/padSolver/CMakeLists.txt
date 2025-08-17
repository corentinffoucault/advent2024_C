
cmake_minimum_required(VERSION  3.10)

project(padSolver)

set(SRCS
    PadSolver.cpp
    Permuter.cpp
    )
    
set(HEADERS
    PadSolver.h
    Permuter.h
    )

add_library(padSolver ${SRCS} ${HEADERS})

target_link_libraries(padSolver Point2D)
