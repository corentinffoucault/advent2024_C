# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day8)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day8.cpp
    )
    
set(HEADERS
    day8.h
    )
    
add_library(day8 ${SRCS} ${HEADERS})

target_link_libraries(day8 days Point2D)
