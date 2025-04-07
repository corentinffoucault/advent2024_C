# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté libPerso
project(Point2D)

# Crée des variables avec les fichiers à compiler
set(SRCS
    Point2D.cpp
    )

set(HEADERS
    Point2D.h
    )

add_library(Point2D ${SRCS} ${HEADERS})