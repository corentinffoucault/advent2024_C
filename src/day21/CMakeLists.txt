
cmake_minimum_required(VERSION  3.10)


project(day21)


set(SRCS
    day21.cpp
    )
    
set(HEADERS
    day21.h
    )

add_library(day21 ${SRCS} ${HEADERS})

add_subdirectory(padSolver)

target_link_libraries(day21 days Point2D padSolver)
