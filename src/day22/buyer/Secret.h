#ifndef SECRET_H_  
#define SECRET_H_

#include <cstdint>

using namespace std;

class Secret {
public:
	Secret(int_least64_t secretCode);
	int_least64_t incrementSecret();
	int getUnitValue();
	int_least64_t getSecretValue();
	~Secret();
private:
	int_least64_t secretCode;
	int_least64_t mix(int_least64_t currentValue);
	int_least64_t prune(int_least64_t currentValue);
};
#endif /* SECRET_H_ */