#include "ComputerMemory.h"

ComputerMemory::ComputerMemory(int_least64_t varA, int_least64_t varB, int_least64_t varC): varA(varA), varB(varB), varC(varC) {
}

ComputerMemory::~ComputerMemory() {
}

const int_least64_t ComputerMemory::getVarA() const {
    return varA;
}

const int_least64_t ComputerMemory::getVarB() const {
    return varB;
}

const int_least64_t ComputerMemory::getVarC() const {
    return varC;
}

void ComputerMemory::setVarA(int_least64_t varA) {
    this->varA = varA;
}

void ComputerMemory::setVarB(int_least64_t varB) {
    this->varB = varB;
}

void ComputerMemory::setVarC(int_least64_t varC) {
    this->varC = varC;

}
