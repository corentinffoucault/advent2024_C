
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté libPerso
project(libPerso)


set(SRCS
    PathUtils.cpp
    StringUtils.cpp
    )

add_library(libPerso ${SRCS} ${HEADERS})
    
add_subdirectory(point2D)

