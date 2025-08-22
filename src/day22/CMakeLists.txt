
cmake_minimum_required(VERSION  3.10)


project(day22)


set(SRCS
    day22.cpp
    )
    
set(HEADERS
    day22.h
    )

add_library(day22 ${SRCS} ${HEADERS})

add_subdirectory(buyer)

target_link_libraries(day22 days buyer)
