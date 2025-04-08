#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "day7.h"
#include "Equation.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day7::day7(fs::path _currentPath) : ADay(_currentPath) {

}

day7::~day7() {
}

string day7::run() {
	day7Data data = createData();
	int_least64_t result = 0L;
	for (Equation equation : data.equations) {
		result += equation.solve();
	}
	return to_string(result);
}

string day7::run2() {
	day7Data data = createData();
	int_least64_t result = 0L;
	for (Equation equation : data.equations) {
		result += equation.solveV2();
	}
	return to_string(result);
}

day7Data day7::createData() {
	day7Data data;
	string line;
	ifstream file_content(currentPath);
	while (getline(file_content, line)) {
		data.equations.push_back(Equation(line));
	}
	return data;
}