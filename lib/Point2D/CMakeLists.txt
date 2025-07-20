
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté libPerso
project(Point2D)


set(SRCS
    Point2D.cpp
    )

set(HEADERS
    Point2D.h
    )

add_library(Point2D ${SRCS} ${HEADERS})