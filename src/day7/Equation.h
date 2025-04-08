
#ifndef EQUATION_H_
#define EQUATION_H_

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

class Equation {
public:
    Equation(string line);
    int_least64_t solve();
    int_least64_t solveV2();
private:
    int_least64_t result = 0L;
    vector<int_least64_t> params;
    bool solveLoop(int_least64_t currentRes, int currentIndex, bool useConcat = false);
    void stringToEquation(string entry);
};

#endif  /* !EQUATION_H_ */