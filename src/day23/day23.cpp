#include <filesystem>
#include <fstream>
#include <unordered_set>
#include <regex>

#include "day23.h"
#include "network/LanKey.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day23::day23(fs::path _currentPath) : ADay(_currentPath) {
}

day23::~day23() {
}

string day23::run() {
    Network network = createData();
    unordered_set<string> result = network.getLansBy3();
    vector<string> computersVector(result.begin(), result.end());
    sort(computersVector.begin(), computersVector.end());
    smatch lanMatch;
	int nbInfo = 0;
    for (auto lan = computersVector.begin(); lan != computersVector.end(); ++lan) {
        
        if (regex_search(*lan, lanMatch, regexContainsT)) {
            nbInfo++;
		}
    }
    return to_string(nbInfo);
}

string day23::run2() {
    Network network = createData();
    unordered_set<string> result = network.getLansByBronkKerbosch();
	vector<string> computersVector(result.begin(), result.end());
	sort(computersVector.begin(), computersVector.end());
    string resultStr = LanKey::generateKey(computersVector);
    return resultStr.substr(0, resultStr.size()-1);
}

Network day23::createData() {
    Network network;

    ifstream file_content(currentPath);
    string line;

    while (getline(file_content, line)) {
		network.add(line);
    }
    return network;
}