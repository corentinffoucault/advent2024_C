# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day10)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day10.cpp
    Topographic.cpp
    )
    
set(HEADERS
    day10.h
    Topographic.h
    )
    
add_library(day10 ${SRCS} ${HEADERS})

target_link_libraries(day10 days Point2D)
