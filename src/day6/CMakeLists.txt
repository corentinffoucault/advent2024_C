# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day6)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day6.cpp
    )
    
set(HEADERS
    day6.h
    )
    
add_library(day6 ${SRCS} ${HEADERS})

target_link_libraries(day6 days Point2D)
