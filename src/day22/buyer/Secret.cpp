#include "Secret.h"

#include <cstdint>

/*
In particular, each buyer's secret number evolves into the next secret number in the sequence via the following process:

Calculate the result of multiplying the secret number by 64. Then, mix this result into the secret number. Finally, prune the secret number.
Calculate the result of dividing the secret number by 32. Round the result down to the nearest integer. Then, mix this result into the secret number. Finally, prune the secret number.
Calculate the result of multiplying the secret number by 2048. Then, mix this result into the secret number. Finally, prune the secret number.

Each step of the above process involves mixing and pruning:

To mix a value into the secret number, calculate the bitwise XOR of the given value and the secret number. Then, the secret number becomes the result of that operation. (If the secret number is 42 and you were to mix 15 into the secret number, the secret number would become 37.)
To prune the secret number, calculate the value of the secret number modulo 16777216. Then, the secret number becomes the result of that operation. (If the secret number is 100000000 and you were to prune the secret number, the secret number would become 16113920.)

*/

Secret::Secret(int_least64_t secretCode): secretCode(secretCode){
}

int Secret::getUnitValue() {
	return secretCode % 10;
}

int_least64_t Secret::getSecretValue() {
    return secretCode;
}

int_least64_t Secret::incrementSecret() {
    secretCode = prune(mix(secretCode * 64));
    secretCode = prune(mix(secretCode / 32));
    secretCode = prune(mix(secretCode * 2048));
    return secretCode;
}

int_least64_t Secret::mix(int_least64_t currentValue) {
    return currentValue ^ secretCode;
}

int_least64_t Secret::prune(int_least64_t currentValue) {
    return currentValue % 16777216;
}

Secret::~Secret() {
}