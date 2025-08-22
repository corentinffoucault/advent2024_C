#include "LanKey.h"

string LanKey::generateKey(vector<string> computers) {
	string result;
	result.reserve(computers.size() * 3);
	for (const auto& computer : computers) {
		result += computer + ',';
	}
	return result;
}
