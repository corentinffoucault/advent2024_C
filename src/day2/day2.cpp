#include <filesystem>
#include <iostream>
#include <regex>
#include <set>
#include <string>


#include "day2.h"


using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day2::day2(fs::path _currentPath) : ADay(_currentPath) {
    
}

day2::~day2() {
}


string day2::run() {
    return "erased";
}

string day2::run2() {
    string my_text;
    long nbSafe = 0;
    
    ifstream file_content(currentPath);
    while (getline(file_content, my_text)) {
        if (isSafe(my_text)) {
			cout << my_text << endl;
        }
        nbSafe += isSafe(my_text) ? 1 : 0;
    }

    return to_string(nbSafe);
}

bool day2::isSafe(string my_text) {
    regex delimiter{ "\\s+" };
    Container splittedLine(sregex_token_iterator(my_text.begin(), my_text.end(), delimiter, -1), {});

    if (toSet(splittedLine).size() < (splittedLine.size() - 1)) {
        return false;
    }

    for (size_t index = 0; index < splittedLine.size(); index++) {
        if (isSafeList(splittedLine, index).empty()) {
            return true;
        }
    }

    return false;
}


vector<size_t> day2::isSafeList(Container splittedLine, size_t dropIndex) {
    Container currentList = splittedLine;
    currentList = copyWithoutIndex(splittedLine, dropIndex);

    int order = 0;
    vector<size_t> indexInError = {};
    for (size_t index = 0; index < currentList.size()-1; index++) {
        int previousItem = stol(currentList[index]);
        int currentItem = stol(currentList[index + 1]);

        int gap = abs(previousItem - currentItem);
        if (gap > 3 || gap < 1) {
            indexInError.push_back(index);
        }

        if (order == 0) {
            order = previousItem > currentItem ? 1 : - 1;
            continue;
        }

        if (previousItem < currentItem && order == 1 ||
            previousItem > currentItem && order == -1) {
            indexInError.push_back(index);
        }
    }

    return indexInError;
}

template <typename T>
vector<T> day2::copyWithoutIndex(const std::vector<T>& input, size_t index) {
    std::vector<T> result;
    result.reserve(input.size() - 1); // Réserver de l'espace pour éviter les réallocations

    std::copy_if(input.begin(), input.end(), std::back_inserter(result),
        [index, &input, i = (size_t)0](const T&) mutable { return i++ != index; });

    return result;
}

set<string> day2::toSet(Container splittedLine) {
    return set<string>(splittedLine.begin(), splittedLine.end());
}
