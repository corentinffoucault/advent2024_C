# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day3
project(day14)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day14.cpp
    Robot.cpp
    )
    
set(HEADERS
    day14.h
    Robot.h
    )
    
add_library(day14 ${SRCS} ${HEADERS})

target_link_libraries(day14 days Point2D)
