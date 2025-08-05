
cmake_minimum_required(VERSION  3.10)


project(day19)


set(SRCS
    day19.cpp
    )
    
set(HEADERS
    day19.h
    )

add_library(day19 ${SRCS} ${HEADERS})

add_subdirectory(towel)

target_link_libraries(day19 days towel)
