# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté day1
project(ADay)

# Crée des variables avec les fichiers à compiler
set(HEADERS
    "ADay.h"
    )

set(SRCS
    "ADay.cpp"
    )
    
add_library(days ${SRCS} ${HEADERS} )