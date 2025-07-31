
cmake_minimum_required(VERSION  3.10)


project(day18)


set(SRCS
    day18.cpp
    )
    
set(HEADERS
    day18.h
    )

add_library(day18 ${SRCS} ${HEADERS})

add_subdirectory(mazeSolver18)

target_link_libraries(day18 days mazeSolver18)
