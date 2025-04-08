# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté libPerso
project(libPerso)

# Crée des variables avec les fichiers à compiler
set(SRCS
    PathUtils.cpp
    StringUtils.cpp
    )

add_library(libPerso ${SRCS} ${HEADERS})
    
add_subdirectory(point2D)

