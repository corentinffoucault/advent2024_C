# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day13)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day13.cpp
    Machine.cpp
    )
    
set(HEADERS
    day13.h
    Machine.h
    )
    
add_library(day13 ${SRCS} ${HEADERS})

target_link_libraries(day13 days Point2D)
