
cmake_minimum_required(VERSION  3.10)

project(keyOrLock)

set(SRCS
    keyOrLock.cpp
    )
    
set(HEADERS
    keyOrLock.h
    )

add_library(keyOrLock ${SRCS} ${HEADERS})

target_link_libraries(keyOrLock)
