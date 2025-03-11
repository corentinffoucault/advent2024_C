// adventOfCode_2024.cpp : définit le point d'entrée de l'application.
//
#include <filesystem>

#include "adventOfCode_2024.h"
#include "src/day1/day1.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
	cout << "Hello CMake.\n";
	day1 day;
	return day.run(fs::current_path().append("..").append("..").append(".."));
}
