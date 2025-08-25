#include "Door.h"

Door::Door() : res(-1) {
}
Door::Door(string v1, string v2, string op, string resultName)
	: v1(v1), v2(v2), op(op), resultName(resultName), res(-1) {
}

int Door::eval(unordered_map<string, Door>& informations,
	unordered_map<string, InitialEntry>& initialEntry) {
	if (res == -1) {
		int value1 = informations.count(v1) ? informations[v1].eval(informations, initialEntry)
			: initialEntry[v1].eval();
		int value2 = informations.count(v2) ? informations[v2].eval(informations, initialEntry)
			: initialEntry[v2].eval();

		if (op == "XOR") res = (value1 != value2) ? 1 : 0;
		else if (op == "AND") res = (value1 == 1 && value2 == 1) ? 1 : 0;
		else if (op == "OR") res = (value1 == 1 || value2 == 1) ? 1 : 0;
		else res = stoi(v1); // fallback
	}
	return res;
}

vector<string> Door::listInitialEntry(unordered_map<string, Door> informations) {
	vector<string> initial;
	if (informations.count(v1)) {
		auto tmp = informations[v1].listInitialEntry(informations);
		initial.insert(initial.end(), tmp.begin(), tmp.end());
	} else {
		initial.push_back(v1);
	}
	if (informations.count(v2)) {
		auto tmp = informations[v2].listInitialEntry(informations);
		initial.insert(initial.end(), tmp.begin(), tmp.end());
	} else {
		initial.push_back(v2);
	}
	return initial;
}

string Door::toString() const {
	return to_string(res);
}

string Door::getResultName() const {
	return resultName;
}

string Door::getOp() const {
	return op;
}

string Door::getV1() const {
	return v1;
}

string Door::getV2() const {
	return v2;
}
