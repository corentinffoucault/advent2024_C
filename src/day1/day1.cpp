#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <regex>

#include "day1.h"


using namespace std;
namespace fs = std::filesystem;
using Container = std::vector<std::string>;

int day1::run(fs::path currentPath) {
    const fs::path path2 = currentPath.append("resources").append("day1.txt");
    cout << path2 << "\n";
    string my_text;
    ifstream file_content(path2);
    std::vector<int> part1;
    std::vector<int> part2;
    std::regex delimiter{ "\\s+" };
    char* output;
    
    while (getline(file_content, my_text)) {
        Container line(std::sregex_token_iterator(my_text.begin(), my_text.end(), delimiter, -1), {});
        part1.push_back(std::stol(line[0]));
        part2.push_back(std::stol(line[1]));
    }
    file_content.close();

    sort(part1.begin(), part1.end());
    sort(part2.begin(), part2.end());

    long result = 0;

    for each(long item in part1) {
        long counter = std::count_if(part2.begin(), part2.end(), [&](int x) { return x == item; });
        result += item * counter;
    }
    cout << "result: " << result << "\n";
    return 0;
}