# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day10)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day10.cpp
    Topographic.cpp
    )
    
set(HEADERS
    day10.h
    Topographic.h
    )
    
add_library(day10 ${SRCS} ${HEADERS})

target_link_libraries(day10 days Point2D)
