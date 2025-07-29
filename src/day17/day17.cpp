#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "day17.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day17::day17(fs::path _currentPath) : ADay(_currentPath) {

}

day17::~day17() {
}

string day17::run() {
    Computer computer = createData();
	vector<int_least64_t> computerResult = computer.solve();
    string result = "";
    for (int_least64_t val : computerResult) {
		result += to_string(val) + ",";
    }
	result.pop_back(); // Remove the last comma
    return result;
}

string day17::run2() {
    Computer computer = createData();
    return  to_string(computer.getValAForReturningInitialInstruction());
}

Computer day17::createData() {
    ifstream file_content(currentPath);
    string line;
    size_t lineIndex = 0;

    getline(file_content, line);
    int_least64_t varA = extractInfo(line, registerRegex);
    getline(file_content, line);
    int_least64_t varB = extractInfo(line, registerRegex);
    getline(file_content, line);
    int_least64_t varC = extractInfo(line, registerRegex);

    getline(file_content, line);
    getline(file_content, line);

    smatch m;
    vector<int> instruction;
    regex_match(line, m, instructionRegex);

    for (char& c : m.str(1)) {
        if (c != ',') {
            stringstream tmp;
            int currentValue;
            tmp << c;
            tmp >> currentValue;
			instruction.push_back(currentValue);
        }
    }
    return Computer(ComputerMemory(varA, varB, varC), Combo(), instruction);
}

int_least64_t day17::extractInfo(string line, regex button) {
    smatch m;
    regex_match(line, m, button);
    stringstream value;
    int_least64_t varValue = 0;
    value << m.str(1);
    value >> varValue;
    return varValue;
}