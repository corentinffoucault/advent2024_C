# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day13)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day13.cpp
    Machine.cpp
    )
    
set(HEADERS
    day13.h
    Machine.h
    )
    
add_library(day13 ${SRCS} ${HEADERS})

target_link_libraries(day13 days Point2D)
