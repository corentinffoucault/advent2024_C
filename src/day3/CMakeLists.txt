# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day3)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day3.cpp
    )
    
set(HEADERS
    day3.h
    )
    
add_library(day3 ${SRCS} ${HEADERS})

target_link_libraries(day3 days)
