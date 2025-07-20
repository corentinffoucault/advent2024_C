
cmake_minimum_required(VERSION  3.10)


project(day9)


set(SRCS
    day9.cpp
    )
    
set(HEADERS
    day9.h
    )
    
add_library(day9 ${SRCS} ${HEADERS})

target_link_libraries(day9 days libPerso)
