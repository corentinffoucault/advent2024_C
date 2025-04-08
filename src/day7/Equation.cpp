#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iosfwd>

#include "../../lib/StringUtils.cpp"
#include "Equation.h"

using namespace std;
using namespace StringUtils;
namespace fs = filesystem;

Equation::Equation(string line) {
	istringstream input{ line };

	string token;
	getline(input, token, ':');
	this->result = stoll(token);
	getline(input, token, ':');
	this->stringToEquation(token);
}

int_least64_t Equation::solve() {
	if (params.size() == 1) {
		return  result == params[0] ? result : 0L;
	}
	return  solveLoop(params[0], 1) ? result : 0L;
}

int_least64_t Equation::solveV2() {
	if (params.size() == 1) {
		return  result == params[0] ? result : 0L;
	}
	return  solveLoop(params[0], 1, true) ? result : 0L;
}

bool Equation::solveLoop(int_least64_t currentRes, int currentIndex, bool useConcat) {
	int_least64_t mul = currentRes * params[currentIndex];
	int_least64_t sum = currentRes + params[currentIndex];
	int_least64_t concat = 0;

	if (useConcat) {
		stringstream strstream;
		strstream << currentRes << params[currentIndex];
		strstream >> concat;
	}

	if (currentIndex == params.size() - 1) {
		return mul == result || sum == result || concat == result;
	}

	bool tmp = false;
	if (mul <= result) {
		tmp = tmp || solveLoop(mul, currentIndex + 1, useConcat);
	}
	if (sum <= result) {
		tmp = tmp || solveLoop(sum, currentIndex + 1, useConcat);
	}
	if (useConcat && concat <= result) {
		tmp = tmp || solveLoop(concat, currentIndex + 1, true);
	}

	return tmp;
}

void Equation::stringToEquation(string entry) {
	string equation = ltrim(rtrim(entry));
	std::istringstream equationString{ equation };

	string token;
	while (getline(equationString, token, ' ')) {
		params.push_back(stoll(token));
	}
}
