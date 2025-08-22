#ifndef BUYERV2_H_  
#define BUYERV2_H_  

#include <unordered_map>
#include <unordered_set>
#include <cstdint>

#include "Buyer.h"
#include "Secret.h"

class BuyerV2: public Buyer {
public:
	BuyerV2(Secret secret);
	void solve(int depth, unordered_map<int, int>* sequenceToValues);
    ~BuyerV2();
private:
    int x0;
    int x1;
    int x2;
    int x3;
    unordered_set<int> alreadySeen;
    int keySequence(int x0, int x1, int x2, int x3, int x4);
};
#endif /* BUYERV2_H_ */