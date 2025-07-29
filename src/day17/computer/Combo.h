#ifndef COMBO_H_  
#define COMBO_H_  

#include <cstdint>

#include "ComputerMemory.h"

class Combo {
   public:  
       Combo();
       int_least64_t getValue(int comboValue, ComputerMemory memory);
       ~Combo();
};
#endif /* COMBO_H_ */