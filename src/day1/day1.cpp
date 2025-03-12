#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <regex>
#include <stdint.h>

#include "day1.h"


using namespace std;
namespace fs = std::filesystem;
using Container = std::vector<std::string>;

day1::day1(fs::path _currentPath) : ADay(_currentPath) {
    
}

day1::~day1() {
}

int day1::run() {
    string my_text;
    std::vector<int> part1;
    std::vector<int> part2;
    std::regex delimiter{ "\\s+" };
    
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
    cout << "result: " << result << "\n";
    return 0;
}
