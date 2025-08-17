#include "Permuter.h"

#include <set>
#include <string>

Permuter::Permuter() {
}

Permuter::~Permuter() {
}

set<string> Permuter::permute(string input) {
    set<string> output;
    permuteHelper(input, "", &output);
    return output;
}

void Permuter::permuteHelper(string str, string result, set<string>* output) {
    if (str.empty()) {
        output->insert(result);
        return;
    }

    for (size_t i = 0; i < str.size(); ++i) {
        string remaining = str.substr(0, i) + str.substr(i + 1);
        permuteHelper(remaining, result + str[i], output);
    }
}