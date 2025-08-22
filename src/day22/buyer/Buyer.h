#ifndef BUYER_H_  
#define BUYER_H_  

#include "Secret.h"

class Buyer {
public:
	Buyer(Secret secret);
	int_least64_t solve(int depth);
    ~Buyer();
protected:
	Secret secret;
};
#endif /* BUYER_H_ */