#include <stdexcept> 

#include "Combo.h"  

Combo::Combo() {  
}  

int_least64_t Combo::getValue(int comboValue, ComputerMemory memory) {  
  switch (comboValue) {  
      case 0:  
          return 0L;  
      case 1:  
          return 1L;  
      case 2:  
          return 2L;  
      case 3:  
          return 3L;  
      case 4: {  
          return memory.getVarA();  
      }  
      case 5: {  
          return memory.getVarB();  
      }  
      case 6: {  
          return memory.getVarC();  
      }  
      default:  
          throw std::runtime_error("combo operand 7 is reserved and will not appear in valid programs"); 
  }  
}  

Combo::~Combo() {  
}
