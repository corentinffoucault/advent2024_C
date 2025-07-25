
cmake_minimum_required(VERSION  3.10)


project(day16)


set(SRCS
    day16.cpp
    )
    
set(HEADERS
    day16.h
    )

add_library(day16 ${SRCS} ${HEADERS})

add_subdirectory(mazeSolver)

target_link_libraries(day16 days Point2D mazeSolver)
