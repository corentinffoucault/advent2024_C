#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <regex>
#include <stdint.h>
#include <set>
#include <algorithm>
#include <locale>

#include "day4.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day4::day4(fs::path _currentPath) : ADay(_currentPath) {
    
}

day4::~day4() {
}

string day4::run() {
    vector<string> matrix;

    string my_text;
    ifstream file_content(currentPath);
    while (getline(file_content, my_text)) {
        matrix.push_back(createLine(my_text));
    }
    return to_string(findXMas(matrix));
}

string day4::run2() {
    vector<string> matrix;

    string my_text;
    ifstream file_content(currentPath);
    while (getline(file_content, my_text)) {
        matrix.push_back(createLine(my_text));
    }
    return to_string(findCrossMas(matrix));
}

string day4::createLine(string line) {
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    return line;
}

bool day4::charIsX(char character) {
    return character == 'x';
}

bool day4::charIsA(char character) {
    return character == 'a';
}

int day4::findCrossMas(vector<string> matrix) {
    int result = 0;
    size_t indexLine = 0;
    for (const string line : matrix) {
        size_t indexCol = 0;
        for (const char letter : line) {
            if (charIsA(letter)) {
                result += findMasLimit(matrix, indexLine, indexCol) ? 1 : 0;
            }
            indexCol++;
        }
        indexLine++;
    }
    return result;
}

int day4::findXMas(vector<string> matrix) {
    int result = 0;
    size_t indexLine = 0;
    for (const string line : matrix) {
        size_t indexCol = 0;
        for (const char letter : line) {
            if (charIsX(letter)) {
                result += findWordLimit(matrix, indexLine, indexCol);
            }
            indexCol++;
        }
        indexLine++;
    }
    return result;
}

int day4::findWordLimit(vector<string> matrix, size_t indexLine, size_t indexCol) {
    int result = 0;
    if (indexLine > 2) {
        if (indexCol > 2) {
            result += findWord(matrix, indexLine, indexCol, -1, -1) ? 1 : 0;
        }
        if (indexCol < matrix[0].length() - 3) {
            result  += findWord(matrix, indexLine, indexCol, -1, 1) ? 1 : 0;
        }
        result += findWord(matrix, indexLine, indexCol, -1, 0);
    }

    if (indexLine < matrix.size() - 3) {
        if (indexCol > 2) {
            result += findWord(matrix, indexLine, indexCol, 1, -1) ? 1 : 0;
        }
        if (indexCol < matrix[0].length() - 3) {
            result += findWord(matrix, indexLine, indexCol, 1, 1) ? 1 : 0;
        }
        result += findWord(matrix, indexLine, indexCol, 1, 0);
    }

    if (indexCol > 2) {
        result += findWord(matrix, indexLine, indexCol, 0, -1);
    }
    if (indexCol < matrix[0].length() - 3) {
        result += findWord(matrix, indexLine, indexCol, 0, 1);
    }
    return result;
}

bool day4::findMasLimit(vector<string> matrix, size_t indexLine, size_t indexCol) {
    return indexLine > 0 && indexLine < matrix.size() - 1 && indexCol > 0 && indexCol < matrix[0].length() - 1 &&
        findDiagMS_top_bottom(matrix, indexLine, indexCol) &&
        findDiagMS_bottom_top(matrix, indexLine, indexCol);
}

bool day4::findDiagMS_top_bottom(vector<string> matrix, size_t indexLine, size_t indexCol) {
    return matrix[indexLine - 1][indexCol - 1] == 'm' && matrix[indexLine + 1][indexCol + 1] == 's' 
        || matrix[indexLine - 1][indexCol - 1] == 's' && matrix[indexLine + 1][indexCol + 1] == 'm';
}

bool day4::findDiagMS_bottom_top(vector<string> matrix, size_t indexLine, size_t indexCol) {
    return matrix[indexLine - 1][indexCol + 1] == 'm' && matrix[indexLine + 1][indexCol - 1] == 's' 
        || matrix[indexLine - 1][indexCol + 1] == 's' && matrix[indexLine + 1][indexCol - 1] == 'm';
}

bool day4::findWord(vector<string> matrix, size_t indexLine, size_t indexCol, int incrLine, int incrCol) {
    size_t currentLine = indexLine + incrLine;
    size_t currentCol = indexCol + incrCol;
    if (matrix[currentLine][currentCol] == 'm') {
        currentLine += incrLine;
        currentCol += incrCol;
        if (matrix[currentLine][currentCol] == 'a') {
            currentLine += incrLine;
            currentCol += incrCol;
            if (matrix[currentLine][currentCol] == 's') {
                return true;
            }
        }
    }
    return false;
}