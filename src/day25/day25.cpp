#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "day25.h"

day25::day25(fs::path _currentPath) : ADay(_currentPath) {
}

day25::~day25() {
}

string day25::run() {
    day25Data data = createData();
    int nbCouple = 0;
    for (auto key : data.keys) {
        for (auto lock : data.locks) {
            if (key.areComplement(lock)) {
                nbCouple++;
            }
        }
    }
	return to_string(nbCouple);
}

string day25::run2() {
    return "nothing";
}

day25Data day25::createData() {
    day25Data data;

    ifstream file_content(currentPath);
    string line;

    smatch entryMatch;
    array<string, 7> block = {};
    size_t index = 0;
    while (getline(file_content, line)) {
        if (!line.empty()) {
            block[index++] = line;
            if (index == 7) {
                if (line[0] == '#') {
                    data.keys.push_back(KeyOrLock::fromStrings(block));
                } else {
                    data.locks.push_back(KeyOrLock::fromStrings(block));
                }
                index = 0;
            }
        }
    }
    file_content.close();
    return data;
}