#ifndef TOWELANALYZER_H_  
#define TOWELANALYZER_H_  

#include "TowelPart.h"
#include <string>
#include <map>

using namespace std;

class TowelAnalyzer {
   public:  
       TowelAnalyzer(TowelPart towelPart);
       int_least64_t isValid(string towel);
       int_least64_t solve(string towel);
       ~TowelAnalyzer();
    private:
        TowelPart towelPart;
        map<string, size_t> seen;
};
#endif /* TowelAnalyzer_H_ */