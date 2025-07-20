
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day1
project(ADay)


set(HEADERS
    "ADay.h"
    )

set(SRCS
    "ADay.cpp"
    )
    
add_library(days ${SRCS} ${HEADERS} )