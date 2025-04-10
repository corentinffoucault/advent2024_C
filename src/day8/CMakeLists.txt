# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day8)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day8.cpp
    )
    
set(HEADERS
    day8.h
    )
    
add_library(day8 ${SRCS} ${HEADERS})

target_link_libraries(day8 days Point2D)
