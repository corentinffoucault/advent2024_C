// adventOfCode_2024.cpp : définit le point d'entrée de l'application.
//
#include <filesystem>

#include "adventOfCode_2024.h"
#include "src/day1/day1.h"
#include "lib/PathUtils.cpp"

using namespace std;
namespace fs = std::filesystem;
using namespace PathUtils;

int main() {
	const int dayIndex = 1;
	ADay* a[dayIndex] = {
		new day1(getResourcesPath(dayIndex))
			};
	return a[dayIndex-1]->run();
}
