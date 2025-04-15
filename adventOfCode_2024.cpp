// adventOfCode_2024.cpp : définit le point d'entrée de l'application.
//
#include <filesystem>

#include "adventOfCode_2024.h"
#include "src/day1/day1.h"
#include "src/day2/day2.h"
#include "src/day3/day3.h"
#include "src/day4/day4.h"
#include "src/day5/day5.h"
#include "src/day6/day6.h"
#include "src/day7/day7.h"
#include "src/day8/day8.h"
#include "src/day9/day9.h"
#include "src/day10/day10.h"
#include "src/day11/day11.h"
#include "src/day12/day12.h"
#include "src/day13/day13.h"
#include "lib/PathUtils.cpp"

using namespace std;
namespace fs = std::filesystem;
using namespace PathUtils;

int main() {
	int dayIndex = 12;
	ADay* a[13] = {
		new day1(getResourcesPath(1)),
		new day2(getResourcesPath(2)),
		new day3(getResourcesPath(3)),
		new day4(getResourcesPath(4)),
		new day5(getResourcesPath(5)),
		new day6(getResourcesPath(6)),
		new day7(getResourcesPath(7)),
		new day8(getResourcesPath(8)),
		new day9(getResourcesPath(9)),
		new day10(getResourcesPath(10)),
		new day11(getResourcesPath(11)),
		new day12(getResourcesPath(12)),
		new day13(getResourcesPath(13)),
			};
	cout << "result day " << dayIndex + 1 << " " << a[dayIndex]->run() << endl;
	cout << "result2 day " << dayIndex + 1 << " " << a[dayIndex]->run2() << endl;
	return 0;
}
