
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day2
project(day2)


set(SRCS
    day2.cpp
    )
    
set(HEADERS
    day2.h
    )
    
add_library(day2 ${SRCS} ${HEADERS})

target_link_libraries(day2 days)
