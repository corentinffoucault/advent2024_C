# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day9)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day9.cpp
    )
    
set(HEADERS
    day9.h
    )
    
add_library(day9 ${SRCS} ${HEADERS})

target_link_libraries(day9 days libPerso)
