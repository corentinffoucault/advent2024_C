#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "day13.h"
#include "MAchine.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day13::day13(fs::path _currentPath) : ADay(_currentPath) {

}

day13::~day13() {
}

string day13::run() {
    vector<Machine> m = createData();
    int_least64_t result = accumulate(m.cbegin(), m.cend(), 0ULL, [this](int_least64_t sum, Machine value) {
        int_least64_t res = value.solveWithCramer();
        return sum + res;
        });
	return to_string(result);
}

string day13::run2() {
    vector<Machine> m = createData();

    int_least64_t result = accumulate(m.cbegin(), m.cend(), 0ULL, [this](int_least64_t sum, Machine value) {
        int_least64_t res = value.solveWithCramer(10000000000000LL);
        return sum + res;
        });
    return to_string(result);
}

vector<Machine> day13::createData() {
    vector<Machine> machines;
    vector<vector<int>> map;
	ifstream file_content(currentPath);
    string line;
    size_t nbLine = 0;
    Point2D currentA = Point2D(0, 0);
    Point2D currentB = Point2D(0, 0);
    while (getline(file_content, line)) {
        if (nbLine % 4 == 0) {
            currentA = extractInfo(line, buttonA);
        } else if (nbLine % 4 == 1) {
            currentB = extractInfo(line, buttonB);
        } else if (nbLine % 4 == 2) {
            machines.push_back(Machine(currentA, currentB, extractInfo(line, prize)));
        }
        nbLine++;
    }
	return machines;
}

Point2D day13::extractInfo(string line, regex button) {
    smatch m;
    regex_match(line, m, button);
    stringstream tmp_x;
    int x = 0;
    int y = 0;
    tmp_x << m.str(1);
    tmp_x >> x;
    stringstream tmp_y;
    tmp_y << m.str(2);
    tmp_y >> y;
    return Point2D(x, y);
}