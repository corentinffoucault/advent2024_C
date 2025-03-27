#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "day1.h"


using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day1::day1(fs::path _currentPath) : ADay(_currentPath) {
    cout << "day1" << endl;
}

day1::~day1() {
}

string day1::run() {
    return "erased";
}

string day1::run2() {
    string my_text;
    vector<int> part1;
    vector<int> part2;
    regex delimiter{ "\\s+" };

    ifstream file_content(currentPath);
    while (getline(file_content, my_text)) {
        Container line(sregex_token_iterator(my_text.begin(), my_text.end(), delimiter, -1), {});
        part1.push_back(stol(line[0]));
        part2.push_back(stol(line[1]));
    }
    file_content.close();

    sort(part1.begin(), part1.end());
    sort(part2.begin(), part2.end());
    int_least64_t result = 0;
    for(long item : part1) {
        int_least64_t counter = count_if(part2.begin(), part2.end(), [&](long x) { return x == item; });
        result += item * counter;
    }
    return to_string(result);
}
