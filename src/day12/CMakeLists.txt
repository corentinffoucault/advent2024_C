# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day12)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day12.cpp
    )
    
set(HEADERS
    day12.h
    )

add_library(day12 ${SRCS} ${HEADERS})

add_subdirectory(garden)

target_link_libraries(day12 days Point2D garden)
