# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day5)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day5.cpp
    )
    
set(HEADERS
    day5.h
    )
    
add_library(day5 ${SRCS} ${HEADERS})

target_link_libraries(day5 days)
