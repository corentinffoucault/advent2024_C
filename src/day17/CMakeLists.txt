
cmake_minimum_required(VERSION  3.10)


project(day17)


set(SRCS
    day17.cpp
    )
    
set(HEADERS
    day17.h
    )

add_library(day17 ${SRCS} ${HEADERS})

add_subdirectory(computer)

target_link_libraries(day17 days computer)
