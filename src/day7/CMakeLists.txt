# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day7)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day7.cpp
    equation.cpp
    )
    
set(HEADERS
    day7.h
    equation.h
    )
    
add_library(day7 ${SRCS} ${HEADERS})

target_link_libraries(day7 days libPerso)
