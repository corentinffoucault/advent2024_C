#include "Buyer.h"
#include <iostream>

Buyer::Buyer(Secret secret): secret(secret) {
}

Buyer::~Buyer() {

}

int_least64_t Buyer::solve(int depth) {
	int_least64_t result = 0;
	for (int i = 0; i < depth; ++i) {
		result = secret.incrementSecret();
	}
	return result;
}