# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(garden)

# Crée des variables avec les fichiers à compiler
set(SRCS
    AGarden.cpp
    Garden.cpp
    Garden2.cpp
    )
    
set(HEADERS
    AGarden.h
    Garden.h
    Garden2.h
    )
    
add_library(garden ${SRCS} ${HEADERS})

target_link_libraries(garden Point2D)
