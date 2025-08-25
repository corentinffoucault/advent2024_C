#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "day24.h"
#include "graph/InitialEntry.h"

day24::day24(fs::path _currentPath) : ADay(_currentPath) {
}

day24::~day24() {
}

string day24::run() {
    Graph graph = createData();
    pair<int_least64_t, unordered_map<string, vector<string>>> result = graph.evalAll();
    return to_string(result.first);
}

string day24::run2() {
    Graph graph = createData();
    graph.solvePart2();
    return "";
}

Graph day24::createData() {
    unordered_map<string, Door> informations;
    unordered_map<string, InitialEntry> initialEntry;

    ifstream file_content(currentPath);
    string line;

    smatch entryMatch;
    while (getline(file_content, line)) {
		if (line.empty()) break;
        regex_search(line, entryMatch, entryRegex);
		initialEntry.insert({ entryMatch[1], InitialEntry(stoi(entryMatch[2])) });
    }
    smatch entryDoors;
    while (getline(file_content, line)) {
        regex_search(line, entryDoors, doorRegex);
        informations.insert({ entryDoors[4], Door(entryDoors[1], entryDoors[3], entryDoors[2], entryDoors[4]) });
    }
    return Graph(informations, initialEntry);
}