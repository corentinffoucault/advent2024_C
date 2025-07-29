#ifndef COMPUTER_H_  
#define COMPUTER_H_  

#include "Combo.h"
#include "ComputerMemory.h"

#include <vector>

using namespace std;

class Computer {
public:
    Computer(ComputerMemory computerMemory, Combo combo, vector<int> instructions);
    ~Computer();
    vector<int_least64_t> solve();
    int_least64_t getValAForReturningInitialInstruction();
private:
    ComputerMemory computerMemory;
    Combo combo;
    vector<int> instructions;
    int_least64_t modulo7 = 0b111;
    vector<int_least64_t> findValidAttempts(const vector<int_least64_t>& candidates, int instruction, ComputerMemory tmpComputerMemory);
    void setComputerMemory(ComputerMemory tmpComputerMemory);
};
#endif /* COMPUTER_H_ */