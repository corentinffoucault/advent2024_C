# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day12)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day12.cpp
    )
    
set(HEADERS
    day12.h
    )

add_library(day12 ${SRCS} ${HEADERS})

add_subdirectory(garden)

target_link_libraries(day12 days Point2D garden)
