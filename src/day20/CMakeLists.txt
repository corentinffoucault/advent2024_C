
cmake_minimum_required(VERSION  3.10)


project(day20)


set(SRCS
    day20.cpp
    )
    
set(HEADERS
    day20.h
    )

add_library(day20 ${SRCS} ${HEADERS})

add_subdirectory(mazeSolver20)

target_link_libraries(day20 days Point2D mazeSolver20)
