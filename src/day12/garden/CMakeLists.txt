
cmake_minimum_required(VERSION  3.10)


project(garden)


set(SRCS
    AGarden.cpp
    Garden.cpp
    Garden2.cpp
    )
    
set(HEADERS
    AGarden.h
    Garden.h
    Garden2.h
    )
    
add_library(garden ${SRCS} ${HEADERS})

target_link_libraries(garden Point2D)
