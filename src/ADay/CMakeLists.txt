# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� day1
project(ADay)

# Cr�e des variables avec les fichiers � compiler
set(HEADERS
    "ADay.h"
    )

set(SRCS
    "ADay.cpp"
    )
    
add_library(days ${SRCS} ${HEADERS} )