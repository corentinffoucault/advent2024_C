# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day4)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day4.cpp
    )
    
set(HEADERS
    day4.h
    )
    
add_library(day4 ${SRCS} ${HEADERS})

target_link_libraries(day4 days)
