// adventOfCode_2024.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets.

#include <filesystem>

#pragma once
using namespace std;
namespace fs = std::filesystem;

class day1 {
    public:
        int run(fs::path currentPath);
};
