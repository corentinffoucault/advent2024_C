#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <regex>

#include "../ADay/ADay.h"
#include "day21.h"
#include "padSolver/PadSolver.h"
#include "padSolver/Permuter.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day21::day21(fs::path _currentPath) : ADay(_currentPath) {

}

day21::~day21() {
}

string day21::run() {
    vector<string> data = createData();
    Permuter permuter;
    PadSolver padSolver(permuter);
    int_least64_t result = 0;
	for (string password : data) {
        int_least64_t instructionSize = padSolver.solve(password, 2);
		cout << "Password: " << password << " Instruction: " << instructionSize << endl;
        regex nonDigit("[^0-9]");
        string onlyDigits = regex_replace(password, nonDigit, "");
		result += instructionSize * stoi(onlyDigits);
	}
    return to_string(result);
}

string day21::run2() {
    vector<string> data = createData();
    Permuter permuter;
    PadSolver padSolver(permuter);
    int_least64_t result = 0;
    for (string password : data) {
        int_least64_t instructionSize = padSolver.solve(password, 25);
        cout << "Password: " << password << " instructionSize: " << instructionSize << endl;
        regex nonDigit("[^0-9]");
        string onlyDigits = regex_replace(password, nonDigit, "");
        result += instructionSize * stoi(onlyDigits);
    }
    return to_string(result);
}

vector<string> day21::createData() {
    vector<string> password;

    ifstream file_content(currentPath);
    string line;

    while (getline(file_content, line)) {
		password.push_back(line);
    }
    return password;
}