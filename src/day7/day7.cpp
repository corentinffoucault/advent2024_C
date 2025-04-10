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
	for (shared_ptr<Equation> equation : data.equations) {
		result += equation->solve();
	}
	return to_string(result);
}

string day7::run2() {
	day7Data data = createData2();
	int_least64_t result = 0L;
	for (shared_ptr<Equation> equation : data.equations) {
		result += equation->solve();
	}
	return to_string(result);
}

day7Data day7::createData() {
	day7Data data;
	string line;
	ifstream file_content(currentPath);
	while (getline(file_content, line)) {
		shared_ptr<Equation> tmp = make_shared<Equation>(line);
		data.equations.push_back(tmp);
	}
	return data;
}

day7Data day7::createData2() {
	day7Data data;
	string line;
	ifstream file_content(currentPath);
	while (getline(file_content, line)) {
		shared_ptr<EquationWithoutConcat> tmp = make_shared<EquationWithoutConcat>(line);
		data.equations.push_back(tmp);
	}
	return data;
}