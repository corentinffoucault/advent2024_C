#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "day9.h"
#include <stdlib.h>

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day9::day9(fs::path _currentPath) : ADay(_currentPath) {

}

day9::~day9() {
}

string day9::run() {
	day9Data data = createData();
	return to_string(calculate(rearange(data)));
}

string day9::run2() {
	day9Data data = createData();
    return to_string(calculate(rearange2(data)));
}

day9Data day9::createData() {
	day9Data data;
	string line;
	ifstream file_content(currentPath);
	bool isNumber = true;
	int index = 0;
    getline(file_content, line);
	data.memory.reserve(line.size());
	for (char& c : line) {
        stringstream tmp;
        int currentValue;
        tmp << c;
        tmp >> currentValue;
		if (isNumber) {
            vector<string> repeated(currentValue, to_string(index));
            data.memory.push_back(repeated);
            index++;
		} else {
            vector<string> repeated(currentValue, ".");
            data.memory.push_back(repeated);
		}
		isNumber = !isNumber;
	}
	return data;
}

day9Data day9::rearange(day9Data data) {
    size_t indexToUpdate = 0;
    size_t indexToMove = data.memory.size() - 1;
    size_t subIndexToUpdate = 0;
    int subIndexToMove = data.memory[indexToMove].size() - 1;

    while (indexToUpdate < indexToMove) {
        while (subIndexToUpdate < data.memory[indexToUpdate].size()) {
            if (data.memory[indexToUpdate][subIndexToUpdate] == ".") {
                while (subIndexToMove > -1) {
                    if (data.memory[indexToMove][subIndexToMove] == ".") {
                        subIndexToMove--;
                    } else {
                        data.memory[indexToUpdate][subIndexToUpdate] = data.memory[indexToMove][subIndexToMove];
                        data.memory[indexToMove][subIndexToMove] = ".";
                        subIndexToMove--;
                        break;
                    }
                }
                if (subIndexToMove == -1) {
                    indexToMove--;
                    subIndexToMove = data.memory[indexToMove].size() - 1;
                    break;
                }
            } else {
                subIndexToUpdate++;
                break;
            }
        }
        if (subIndexToUpdate == data.memory[indexToUpdate].size()) {
            indexToUpdate++;
            subIndexToUpdate = 0;
        }
    }
    return data;
}

day9Data day9::rearange2(day9Data data) {
    int indexToMove = data.memory.size() - 1;

    while (0 < indexToMove) {
        while (data.memory[indexToMove].size() > 0 && data.memory[indexToMove][0] == ".") {
            indexToMove--;
        }

        int indexToUpdate = 0;
        while (indexToUpdate<indexToMove && indexToMove>-1) {
            if (data.memory[indexToUpdate].size() > 0 && data.memory[indexToMove].size() > 0 && data.memory[indexToUpdate][0] == "." && data.memory[indexToUpdate].size() >= data.memory[indexToMove].size()) {
                break;
            }
            indexToUpdate++;
        }

        if (indexToUpdate < indexToMove) {
            if (data.memory[indexToUpdate].size() == data.memory[indexToMove].size()) {
                vector<string> movedVector(data.memory[indexToMove].size(), data.memory[indexToMove][0]);
                data.memory[indexToUpdate] = movedVector;
                vector<string> pointedVector(data.memory[indexToMove].size(), ".");
                data.memory[indexToMove] = pointedVector;
          } else {
                size_t moveSize = data.memory[indexToMove].size();
                size_t updatedSize = data.memory[indexToUpdate].size();
                string currentValue = data.memory[indexToMove][0];
                vector<string> pointedVector(moveSize, ".");
                data.memory[indexToMove] = pointedVector;
                vector<string> pointedVectorBis(updatedSize - moveSize, ".");
                data.memory[indexToUpdate] = pointedVectorBis;
                vector<string> movedVector(moveSize, currentValue);
                data.memory.insert(data.memory.begin() + indexToUpdate, movedVector);
          }
      }
        indexToMove--;
  }
    return data;
}

int_least64_t day9::calculate(day9Data data) {
    int_least64_t index = 0;
    int_least64_t result = 0;
    for(vector<string> subMemory : data.memory) {
        for (string c : subMemory) {
           if (c != ".") {
               stringstream tmp;
               int_least64_t currentValue;
               tmp << c;
               tmp >> currentValue;
               result += index * currentValue;
               index++;
           } else {
               index++;
           }
        }
    }
    return result;
}