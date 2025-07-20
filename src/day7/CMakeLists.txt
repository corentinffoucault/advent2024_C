
cmake_minimum_required(VERSION  3.10)


project(day7)


set(SRCS
    day7.cpp
    equation.cpp
    )
    
set(HEADERS
    day7.h
    equation.h
    )
    
add_library(day7 ${SRCS} ${HEADERS})

target_link_libraries(day7 days libPerso)
