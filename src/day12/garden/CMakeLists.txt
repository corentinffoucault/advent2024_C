# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(garden)

# Cr�e des variables avec les fichiers � compiler
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
