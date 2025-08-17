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
#include "src/day14/day14.h"
#include "src/day15/day15.h"
#include "src/day16/day16.h"
#include "src/day17/day17.h"
#include "src/day18/day18.h"
#include "src/day19/day19.h"
#include "src/day20/day20.h"
#include "src/day21/day21.h"
#include "lib/PathUtils.cpp"

using namespace std;
namespace fs = std::filesystem;
using namespace PathUtils;

int main() {
	int dayIndex = 20;
	ADay* a[21] = {
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
		new day14(getResourcesPath(14)),
		new day15(getResourcesPath(15)),
		new day16(getResourcesPath(16)),
		new day17(getResourcesPath(17)),
		new day18(getResourcesPath(18)),
		new day19(getResourcesPath(19)),
		new day20(getResourcesPath(20)),
		new day21(getResourcesPath(21)),
			};
	cout << "result day " << dayIndex + 1 << " " << a[dayIndex]->run() << endl;
	cout << "result2 day " << dayIndex + 1 << " " << a[dayIndex]->run2() << endl;
	return 0;
}
