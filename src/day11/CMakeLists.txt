# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day11)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day11.cpp
    )
    
set(HEADERS
    day11.h
    )
    
add_library(day11 ${SRCS} ${HEADERS})

target_link_libraries(day11 days libPerso)
