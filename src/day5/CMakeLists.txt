# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day5)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day5.cpp
    )
    
set(HEADERS
    day5.h
    )
    
add_library(day5 ${SRCS} ${HEADERS})

target_link_libraries(day5 days)
