
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day1
project(day1)


set(SRCS
    day1.cpp
    )
    
set(HEADERS
    day1.h
    )

add_library(day1 ${SRCS} ${HEADERS})

target_link_libraries(day1 days)