
cmake_minimum_required(VERSION  3.10)


project(day24)


set(SRCS
    day24.cpp
    )
    
set(HEADERS
    day24.h
    )

add_library(day24 ${SRCS} ${HEADERS})

add_subdirectory(graph)

target_link_libraries(day24 days graph)
