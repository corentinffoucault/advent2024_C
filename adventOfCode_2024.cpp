// adventOfCode_2024.cpp : définit le point d'entrée de l'application.
//
#include <filesystem>

#include "adventOfCode_2024.h"
#include "src/day1/day1.h"
#include "src/day2/day2.h"
#include "src/day3/day3.h"
#include "src/day4/day4.h"
#include "src/day5/day5.h"
#include "lib/PathUtils.cpp"

using namespace std;
namespace fs = std::filesystem;
using namespace PathUtils;

int main() {
	int dayIndex = 4;
	ADay* a[5] = {
		new day1(getResourcesPath(1)),
		new day2(getResourcesPath(2)),
		new day3(getResourcesPath(3)),
		new day4(getResourcesPath(4)),
		new day5(getResourcesPath(5))
			};
	cout << "result day " << dayIndex + 1 << " " << a[dayIndex]->run() << endl;
	cout << "result2 day " << dayIndex + 1 << " " << a[dayIndex]->run2() << endl;
	return 0;
}
