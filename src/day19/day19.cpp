#include <filesystem>
#include <fstream>
#include <regex>

#include "../ADay/ADay.h"
#include "day19.h"
#include "towel/TowelAnalyzer.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day19::day19(fs::path _currentPath) : ADay(_currentPath) {

}

day19::~day19() {
}

string day19::run() {
    day19Data data = createData();
	TowelAnalyzer towelTools(data.towelPart);
    int_least64_t nbValid = 0;
	for (string towel : data.towels) {
		if (towelTools.isValid(towel) > 0) {
            nbValid++;
		}
	}
	return to_string(nbValid);
}

string day19::run2() {
    day19Data data = createData();
    TowelAnalyzer towelTools(data.towelPart);
    int_least64_t nbValid = 0;
    for (string towel : data.towels) {
        nbValid+= towelTools.isValid(towel);
    }
    return to_string(nbValid);
}

day19Data day19::createData() {
    ifstream file_content(currentPath);
    string line;
    vector<string> towels;
    TowelPart towelParts(' ');


    regex delimiter{ ", " };
    getline(file_content, line);

    Container splittedLine(sregex_token_iterator(line.begin(), line.end(), delimiter, -1), {});
	for (const string& part : splittedLine) {
        towelParts.addTowelPart(part);
	}
    getline(file_content, line);

    while (getline(file_content, line)) {
		towels.push_back(line);
    }
    return { towelParts, towels };
}