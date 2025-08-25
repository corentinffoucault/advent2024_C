
cmake_minimum_required(VERSION  3.10)


project(day25)


set(SRCS
    day25.cpp
    )
    
set(HEADERS
    day25.h
    )

add_library(day25 ${SRCS} ${HEADERS})

add_subdirectory(keyOrLock)

target_link_libraries(day25 days keyOrLock)
