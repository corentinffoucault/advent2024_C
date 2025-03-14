﻿// adventOfCode_2024.cpp : définit le point d'entrée de l'application.
//
#include <filesystem>

#include "adventOfCode_2024.h"
#include "src/day1/day1.h"
#include "src/day2/day2.h"
#include "lib/PathUtils.cpp"

using namespace std;
namespace fs = std::filesystem;
using namespace PathUtils;

int main() {
	int dayIndex = 1;
	ADay* a[2] = {
		new day1(getResourcesPath(1)),
		new day2(getResourcesPath(2))
			};
	cout << "result day " << dayIndex + 1 << " " << a[dayIndex]->run();
	return 0;
}
