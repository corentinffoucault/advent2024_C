# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� libPerso
project(libPerso)

# Cr�e des variables avec les fichiers � compiler
set(SRCS
    PathUtils.cpp
    )

add_library(lib ${SRCS} ${HEADERS})