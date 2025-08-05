#include "TowelAnalyzer.h"
#include "TowelPart.h"

TowelAnalyzer::TowelAnalyzer(TowelPart towelPart) : towelPart(towelPart) {
}

TowelAnalyzer::~TowelAnalyzer() {
}

int_least64_t TowelAnalyzer::solve(string towel) {
	seen.clear();
    size_t currentPos = isValid(towel);
	size_t nbValid = 0;
    if (currentPos > 0) {
        nbValid += currentPos;
    }
    return nbValid;
}

int_least64_t TowelAnalyzer::isValid(string towel) {
    int_least64_t currentRes = 0;
	
	 if (towel.size() == 0) {
         return 1;
     }
     if (!seen.contains(towel)) {
         vector<string> subTowels = towelPart.getPossibleTowelRemovingTowelPart(towel);
		 for (const string subTowel : subTowels) {
             int_least64_t isValidRes = isValid(subTowel);
             currentRes += isValidRes;
		 }
         seen[towel] = currentRes;
     } else {
         currentRes += seen[towel];
     }
	 return currentRes;
}