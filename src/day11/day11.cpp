#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <numeric>

#include "../ADay/ADay.h"
#include "day11.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day11::day11(fs::path _currentPath) : ADay(_currentPath) {

}

day11::~day11() {
}

string day11::run() {
    limit = 25;
    cache.clear();
    vector<int_least64_t> data = createData();
    int_least64_t result = accumulate(data.cbegin(), data.cend(), 0, [this](int_least64_t sum, const int_least64_t& value) {
        return sum + buildNextLevel(value, 0);
        });
	return to_string(result);
}

string day11::run2() {
	cache.clear();
    limit = 75;
    vector<int_least64_t> data = createData();
    int_least64_t result = accumulate(data.cbegin(), data.cend(), 0ULL, [this](int_least64_t sum, const int_least64_t& value) {
        int_least64_t res = buildNextLevel(value, 0);
        return sum + res;
        });
    return to_string(result);
}

vector<int_least64_t> day11::createData() {
    vector<int_least64_t> data;
	string line;
	ifstream file_content(currentPath);
    getline(file_content, line);
    string numberInString;
    istringstream input{ line };
	while(getline(input, numberInString, ' ')) {
        stringstream tmp;
        int_least64_t currentValue;
        tmp << numberInString;
        tmp >> currentValue;
		data.push_back(currentValue);
	}
	return data;
}

int_least64_t day11::buildNextLevel(int_least64_t currentValue, int indexLoop) {
    if (indexLoop == limit) {
        return 1;
    }
	string key = format("{}_{}", currentValue, indexLoop);
    if (cache.contains(key)) {
        return cache[key];
    }
    int_least64_t res;
    if (currentValue == 0) {
        res = buildNextLevel(1, indexLoop + 1);
    } else {
        string stringValue = to_string(currentValue);
        int size = stringValue.length();
        if (size % 2 == 0) {
            int semiSize = size / 2;
            res = buildNextLevel(stoll(stringValue.substr(0, semiSize)), indexLoop + 1) +
                buildNextLevel(stoll(stringValue.substr(semiSize)), indexLoop + 1);
        } else {
            res = buildNextLevel(currentValue * 2024, indexLoop + 1);
        }
    }
    cache[key] = res;
    return res;
}