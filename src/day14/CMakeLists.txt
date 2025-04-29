# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day3
project(day14)

# Crée des variables avec les fichiers à compiler
set(SRCS
    day14.cpp
    Robot.cpp
    )
    
set(HEADERS
    day14.h
    Robot.h
    )
    
add_library(day14 ${SRCS} ${HEADERS})

target_link_libraries(day14 days Point2D)
