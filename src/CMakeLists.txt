
# Nous voulons un cmake "r�cent" pour utiliser les derni�res fonctionnalit�s
cmake_minimum_required(VERSION  3.10)

# Notre projet est �tiquet� src
project(days)

# Cr�e des variables avec les fichiers � compiler
add_subdirectory(ADay)
add_subdirectory(day1)
add_subdirectory(day2)