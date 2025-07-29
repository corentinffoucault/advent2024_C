#include "Computer.h"
#include "Computer.h"

#include <cmath>
#include <iostream>
#include <format>
#include <numeric>
#include <map>
#include <algorithm>

Computer::Computer(ComputerMemory computerMemory, Combo combo, vector<int> instructions): computerMemory(computerMemory), combo(combo), instructions(instructions) {
}

Computer::~Computer() {
}

vector<int_least64_t> Computer::solve() {
    vector<int_least64_t> result;
	int index = 0;
	int nbLoop = 0;
    while (index < instructions.size()) {
		nbLoop++;
		int currentInstruction = instructions[index++];
		int operand = instructions[index++];
		switch (currentInstruction) {
			case 0:
			{
				cout << format("instruction: {} operand: {} combo: {}", currentInstruction, operand, combo.getValue(operand, computerMemory)) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				computerMemory.setVarA(computerMemory.getVarA() / pow(2,combo.getValue(operand, computerMemory)));
				break;
			}
			case 1:
			{
				cout << format("instruction: {} operand: {} ", currentInstruction, operand) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				computerMemory.setVarB(computerMemory.getVarB() ^ operand);
				break;
			}
			case 2:
			{
				cout << format("instruction: {} operand: $operand combo: {}", currentInstruction, operand, combo.getValue(operand, computerMemory)) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				int_least64_t flooredValue = floor(combo.getValue(operand, computerMemory) % 8);
				computerMemory.setVarB(flooredValue & modulo7);
				break;
			}
			case 3:
			{
				cout << format("instruction: {} operand: {} ", currentInstruction, operand) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				if (computerMemory.getVarA() != 0L) {
					index = operand;
				}
				break;
			}
			case 4:
			{
				cout << format("instruction: {} operand: {} ", currentInstruction, operand) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				computerMemory.setVarB(computerMemory.getVarB() ^ computerMemory.getVarC());
				break;
			}
			case 5:
			{
				cout << format("instruction: {} operand: {} combo: {}", currentInstruction, operand, combo.getValue(operand, computerMemory)) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				result.push_back(floor(combo.getValue(operand, computerMemory) % 8));
				break;
			}
			case 6:
			{
				cout << format("instruction: {} operand: {} combo: {}", currentInstruction, operand, combo.getValue(operand, computerMemory)) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB() , computerMemory.getVarC()) << endl;
				computerMemory.setVarB(computerMemory.getVarA() / pow(2, combo.getValue(operand, computerMemory)));
				break;
			}
			case 7:
			{
				cout << format("instruction: {} operand: {} combo: {}", currentInstruction, operand, combo.getValue(operand, computerMemory)) << endl;
				cout << format("A: {} B: {} C: {}", computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC()) << endl;
				computerMemory.setVarC(computerMemory.getVarA() / pow(2, combo.getValue(operand, computerMemory)));
				break;
			}
		}
    }
    return result;
}

int_least64_t Computer::getValAForReturningInitialInstruction() {
	ComputerMemory tmpComputerMemory = ComputerMemory(computerMemory.getVarA(), computerMemory.getVarB(), computerMemory.getVarC());

	vector<int_least64_t> candidates = { 0 };

	for (vector<int>::reverse_iterator instruction = instructions.rbegin(); instruction != instructions.rend(); ++instruction) {
		vector<int_least64_t> newCandidates = findValidAttempts(candidates, *instruction, tmpComputerMemory);
		candidates = move(newCandidates);
	}

	return candidates.front();
}


vector<int_least64_t> Computer::findValidAttempts(const vector<int_least64_t>& candidates, int instruction, ComputerMemory tmpComputerMemory) {
	std::vector<int_least64_t> results;

	for (int_least64_t candidate : candidates) {
		int_least64_t shifted = candidate << 3;

		for (int_least64_t attempt = shifted; attempt <= shifted + 8; ++attempt) {
			tmpComputerMemory.setVarA(attempt);
			this->setComputerMemory(tmpComputerMemory);

			vector<int_least64_t> result = this->solve();
			if (!result.empty() && result.front() == instruction) {
				results.push_back(attempt);
			}
		}
	}

	return results;
}

void Computer::setComputerMemory(ComputerMemory tmpComputerMemory) {
	this->computerMemory = tmpComputerMemory;
}
