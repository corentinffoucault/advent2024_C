
cmake_minimum_required(VERSION  3.10)


project(day12)


set(SRCS
    day12.cpp
    )
    
set(HEADERS
    day12.h
    )

add_library(day12 ${SRCS} ${HEADERS})

add_subdirectory(garden)

target_link_libraries(day12 days Point2D garden)
