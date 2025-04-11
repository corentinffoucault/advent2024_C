# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day9)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day9.cpp
    )
    
set(HEADERS
    day9.h
    )
    
add_library(day9 ${SRCS} ${HEADERS})

target_link_libraries(day9 days libPerso)
