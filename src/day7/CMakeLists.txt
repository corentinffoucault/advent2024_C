# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day7)

# Cr�e des variables avec les fichiers � compiler
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
