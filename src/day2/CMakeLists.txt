# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day2
project(day2)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day2.cpp
    )
    
set(HEADERS
    day2.h
    )
    
add_library(day2 ${SRCS} ${HEADERS})

target_link_libraries(day2 days)
