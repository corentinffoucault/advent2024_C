# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day4)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day4.cpp
    )
    
set(HEADERS
    day4.h
    )
    
add_library(day4 ${SRCS} ${HEADERS})

target_link_libraries(day4 days)
