
cmake_minimum_required(VERSION  3.10)

project(network)

set(SRCS
    Connection.cpp
    Computer23.cpp
    Network.cpp
    LanKey.cpp
    )
    
set(HEADERS
    Connection.h
    Computer23.h
    Network.h
    LanKey.h
    )

add_library(network ${SRCS} ${HEADERS})

target_link_libraries(network)
