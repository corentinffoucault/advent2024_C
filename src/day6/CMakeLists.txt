# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day6)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day6.cpp
    )
    
set(HEADERS
    day6.h
    )
    
add_library(day6 ${SRCS} ${HEADERS})

target_link_libraries(day6 days Point2D)
