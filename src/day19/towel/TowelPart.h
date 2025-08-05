#ifndef TOWELPART_H_  
#define TOWELPART_H_  

#include <vector>
#include <string>
#include <map>

using namespace std;

class TowelPart {
   public:  
       TowelPart(char currentVal);
       TowelPart();
       vector<string> getPossibleTowelRemovingTowelPart(string towel);
       void addTowelPart(string towel);
       ~TowelPart();
    private:
        char currentVal;
		map<char, TowelPart> nextVals;
        bool isFinal = false;
};
#endif /* TowelPart_H_ */