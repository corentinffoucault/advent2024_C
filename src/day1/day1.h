// adventOfCode_2024.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#include <filesystem>

#pragma once
using namespace std;
namespace fs = std::filesystem;

class day1 {
    public:
        int run(fs::path currentPath);
};
