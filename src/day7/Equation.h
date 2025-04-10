#ifndef EQUATION_H_  
#define EQUATION_H_  

#include <cstdint>  
#include <string>  
#include <vector>  

using namespace std;  

class Equation {  
public:  
 Equation(string line);  
 virtual ~Equation() = default;  
 int_least64_t solve();  
protected:  
 int_least64_t result = 0L;  
 vector<int_least64_t> params;  
 virtual bool solveLoop(int_least64_t currentRes, int currentIndex);  
 void stringToEquation(string entry);  
};  

class EquationWithoutConcat : public Equation {  
public:  
 EquationWithoutConcat(string line) : Equation(line) {}
 ~EquationWithoutConcat() override = default;   
protected:  
 bool solveLoop(int_least64_t currentRes, int currentIndex) override;  
};  

#endif  /* !EQUATION_H_ */