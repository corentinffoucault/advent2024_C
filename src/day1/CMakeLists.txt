# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day1
project(day1)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    day1.cpp
    )
    
set(HEADERS
    day1.h
    )

add_library(day1 ${SRCS} ${HEADERS})

target_link_libraries(day1 days)