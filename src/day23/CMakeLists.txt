
cmake_minimum_required(VERSION  3.10)


project(day23)


set(SRCS
    day23.cpp
    )
    
set(HEADERS
    day23.h
    )

add_library(day23 ${SRCS} ${HEADERS})

add_subdirectory(network)

target_link_libraries(day23 days network)
