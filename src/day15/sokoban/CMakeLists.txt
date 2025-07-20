
cmake_minimum_required(VERSION  3.10)


project(sokoban)


set(SRCS
    ASokoban.cpp
    Sokoban.cpp
    Sokoban2.cpp
    )
    
set(HEADERS
    ASokoban.h
    Sokoban.h
    Sokoban2.h
    )
    
add_library(sokoban ${SRCS} ${HEADERS})

target_link_libraries(sokoban Point2D)
