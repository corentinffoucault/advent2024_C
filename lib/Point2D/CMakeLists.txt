# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� libPerso
project(Point2D)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    Point2D.cpp
    )

set(HEADERS
    Point2D.h
    )

add_library(Point2D ${SRCS} ${HEADERS})