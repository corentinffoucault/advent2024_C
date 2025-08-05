
cmake_minimum_required(VERSION  3.10)

project(towel)

set(SRCS
    TowelPart.cpp
    TowelAnalyzer.cpp
    )
    
set(HEADERS
    TowelPart.h
    TowelAnalyzer.h
    )

add_library(towel ${SRCS} ${HEADERS})

target_link_libraries(towel)
