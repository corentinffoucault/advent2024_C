#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "day5.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day5::day5(fs::path _currentPath) : ADay(_currentPath) {
    
}

day5::~day5() {
}

string day5::run() {
	day5Data data = createData();
    return to_string(analyseAllLine(data)[0]);
}

string day5::run2() {
    day5Data data = createData();
    return to_string(analyseAllLine(data)[1]);
}

day5Data day5::createData() {
    day5Data data;
    string line;
    ifstream file_content(currentPath);
    bool isInPartOrder = true;
    while(getline(file_content, line)) {
        if (isInPartOrder) {
            if (line == "") {
                isInPartOrder = false;
            } else {
                data.orders.insert(line);
            }
        } else {
            data.linesToAnalyses.push_back(line);
        }
    }
    return data;
}

int* day5::analyseAllLine(day5Data data) {
    int result[2] = { 0, 0 };
	for (string line : data.linesToAnalyses) {
		int numberForLine = validNumber(data, line);
		if (numberForLine < 0) {
			result[1] += -numberForLine;
		} else {
			result[0] += numberForLine;
		}
	}
    return result;
}

int day5::validNumber(day5Data data, string line) {
    std::istringstream input{line};
    vector<string> splittedLine;

    string token;
	while (getline(input, token, ',')) {
        splittedLine.push_back(token);
	}

    int index = 0;
	for (string item1 : splittedLine) {
        if (index < splittedLine.size() - 1) {
			for (int index2 = index + 1; index2 < splittedLine.size(); index2++) {
				if (data.orders.contains(splittedLine[index2]+"|"+ item1)) {
                    vector<string> reorderedArray = reorder(data, splittedLine);
                    return -stoi(reorderedArray[reorderedArray.size() / 2]);
				}
			}
        }
        index++;
	}
    return stoi(splittedLine[splittedLine.size() / 2]);
}

vector<string> day5::reorder(day5Data data, vector<string> splittedLine) {
    vector<string> newList;
	size_t  originalSize = splittedLine.size();
    while (newList.size() < originalSize) {
        if (splittedLine.size() == 0) {
            break;
        }
        int index = 0;
        while (index < splittedLine.size()) {
            if (checkIsFirst(data, splittedLine[index], splittedLine)) {
                break;
            }
            index++;
        }
        newList.push_back(splittedLine[index]);
        splittedLine.erase(splittedLine.begin() + index);
    }
    return newList;
}

bool day5::checkIsFirst(day5Data data, string item, vector<string> splittedLine) {
    bool isFirst = true;
	for (string item1 : splittedLine) {
		if (data.orders.contains(item1+"|"+item)) {
			isFirst = false;
		}
	}
    return isFirst;
}