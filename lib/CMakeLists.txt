# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� libPerso
project(libPerso)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    PathUtils.cpp
    StringUtils.cpp
    )

add_library(libPerso ${SRCS} ${HEADERS})
    
add_subdirectory(point2D)

