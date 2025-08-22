
cmake_minimum_required(VERSION  3.10)

project(buyer)

set(SRCS
    Buyer.cpp
    BuyerV2.cpp
    Secret.cpp
    )
    
set(HEADERS
    Buyer.h
    BuyerV2.h
    Secret.h
    )

add_library(buyer ${SRCS} ${HEADERS})

target_link_libraries(buyer)
