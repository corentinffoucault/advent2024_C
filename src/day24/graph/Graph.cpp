#include "Graph.h"
#include <format>
#include <fstream>
#include <iostream>
#include <unordered_set>

Graph::Graph(unordered_map<string, Door> informations, unordered_map<string, InitialEntry> initialEntry) : informations(informations), initialEntry(initialEntry) {
}

Graph::~Graph() {
}

pair<int_least64_t, unordered_map<string, vector<string>>> Graph::evalAll() {
	unordered_set<string> zValue;
	unordered_map<string, vector<string>> ztoXY;

	for (auto& [key, value] : informations) {
		value.eval(informations, initialEntry);
		if (!key.empty() && key[0] == 'z') {
			zValue.insert(key);
		}
	}

	vector<string> sortedZ(zValue.begin(), zValue.end());
	sort(sortedZ.begin(), sortedZ.end(), greater<>());

	string binaryResult;
	for (auto& it : sortedZ) {
		binaryResult += to_string(informations[it].eval(informations, initialEntry));
		ztoXY[it] = informations[it].listInitialEntry(informations);
	}

	int_least64_t value = stoll(binaryResult, nullptr, 2);
	return { value, ztoXY };
}

void Graph::solvePart2() {

	vector<string> x, y;
	for (auto& [k, v] : initialEntry) {
		if (!k.empty() && k[0] == 'x') x.push_back(k);
		else if (!k.empty() && k[0] == 'y') y.push_back(k);
	}

	cout << "digraph G {\n";

	// X subgraph
	cout << returnListInString(x, "->");

	// Y subgraph
	cout << returnListInString(x, "->");

	// AND gates
	cout << returnInformationInString(" ", "AND", "pink", "square");

	// OR gates
	cout << returnInformationInString(" ", "OR", "yellow", "diamond");

	// XOR gates
	cout << returnInformationInString(" ", "XOR", "lightblue", "house");

	// Connections
	for (auto& [k, value] : informations) {
		cout << "  " << value.getV1() << " -> " << k << "\n";
		cout << "  " << value.getV2() << " -> " << k << "\n";
	}

	cout << "}";
}

string Graph::returnInformationInString(string separator, string operatorStr, string color, string shape) {
	string start = std::format("  subgraph {{\n    node [style=filled,color={},shape={}]\n    ", color, shape);
	string end = "\n  }\n";
	string result;
	result.reserve(start.size() + end.size() + informations.size() * (3 + separator.size()));
	result += start;
	for (auto& [k, gate] : informations) {
		if (gate.getOp() == operatorStr) {
			result += gate.getResultName() + separator;
		}
	}
	result += end;
	return result;
}

string Graph::returnListInString(vector<string> items, string separator) {
	string start = "  subgraph {\n    node [style=filled,color=gray]\n    ";
	string end = " [color=\"none\"]\n  }\n";
	string result;
	result.reserve(start.size() + end.size() + items.size() * (items[0].size() + separator.size()));
	result += start;
	for (size_t i = 0; i < items.size(); i++) {
		result+=items[i] + separator;
	}
	result += end;
	return result;
}

void Graph::extractInfo(const string& fileName) {
	ifstream in(fileName);
	if (!in.is_open()) {
		cerr << "Error opening " << fileName << endl;
		return;
	}

	string line;
	while (getline(in, line)) {
		if (line.empty()) break;
		auto pos = line.find(": ");
		if (pos != string::npos) {
			string key = line.substr(0, pos);
			int val = stoi(line.substr(pos + 2));
			initialEntry[key] = InitialEntry(val);
		}
	}

	while (getline(in, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string a, op, b, arrow, result;
		ss >> a >> op >> b >> arrow >> result;
		informations[result] = Door(a, b, op, result);
	}
	in.close();
}