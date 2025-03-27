
# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION  3.10)

# Notre projet est étiqueté src
project(days)

# Crée des variables avec les fichiers à compiler
add_subdirectory(ADay)
add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
add_subdirectory(day4)
add_subdirectory(day5)