#ifndef COMPUTER_MEMORY_H_  
#define COMPUTER_MEMORY_H_  

#include <cstdint>

class ComputerMemory {
   public:  
       ComputerMemory(int_least64_t varA, int_least64_t varB, int_least64_t varC);
       ~ComputerMemory();

       const int_least64_t getVarA() const;
       const int_least64_t getVarB() const;
       const int_least64_t getVarC() const;
       void setVarA(int_least64_t varA);
       void setVarB(int_least64_t varB);
       void setVarC(int_least64_t varC);
   private:  
       int_least64_t varA;
       int_least64_t varB;
       int_least64_t varC;
};
#endif /* COMPUTER_MEMORY_H_ */