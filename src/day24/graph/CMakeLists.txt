
cmake_minimum_required(VERSION  3.10)

project(graph)

set(SRCS
    Door.cpp
    InitialEntry.cpp
    Graph.cpp
    )
    
set(HEADERS
    Door.h
    InitialEntry.h
    Graph.h
    )

add_library(graph ${SRCS} ${HEADERS})

target_link_libraries(graph)
