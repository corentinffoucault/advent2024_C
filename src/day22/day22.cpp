#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>  
#include <vector>  
#include <unordered_map>  

#include "../ADay/ADay.h"
#include "buyer/Buyer.h"
#include "buyer/BuyerV2.h"
#include "day22.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day22::day22(fs::path _currentPath) : ADay(_currentPath) {
}

day22::~day22() {
}

string day22::run() {
    vector<Secret> secrets = createData();
    int_least64_t result = 0;
	for (Secret secret : secrets) {
        Buyer buyer(secret);
        result += buyer.solve(2000);
	}
    return to_string(result);
}

string day22::run2() {
    vector<Secret> secrets = createData();
    unordered_map<int, int> sequenceToValues;
    sequenceToValues.reserve(130320);
	// TODO: speed up bu creating a map of secret value end the depth end all possible value?
    for (Secret secret : secrets) {
        BuyerV2 buyer(secret);
        buyer.solve(2000, &sequenceToValues);
    }
    int result = 0;
	for (auto& [key, value] : sequenceToValues) {
		result = max(result, value);
	}
    return to_string(result);
}

vector<Secret> day22::createData() {
    vector<Secret> secrets;

    ifstream file_content(currentPath);
    string line;

    while (getline(file_content, line)) {
        stringstream tmp_x;
        int_least64_t x = 0;
        tmp_x << line;
        tmp_x >> x;
        Secret secret(x);
        secrets.push_back(secret);
    }
    return secrets;
}