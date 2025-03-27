#include <filesystem>
#include <regex>
#include <string>

#include "day3.h"


using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day3::day3(fs::path _currentPath) : ADay(_currentPath) {

}

day3::~day3() {
}

string day3::run() {
	return "erased";
}

string day3::run2() {
	string my_text;
	multiplyReaderState* currentState = new multiplyReaderState();

	ifstream file_content(currentPath);
	while (getline(file_content, my_text)) {
		analyzeLine(my_text, currentState);
	}

	return to_string(currentState->currentValue);
}

void day3::analyzeLine(string line, multiplyReaderState* currentState) const {
	for (std::sregex_iterator item = words_begin; item != words_end; ++item) {
		smatch match = *item;
		string match_str = match.str();
		if (match_str == "do()") {
			currentState->multipliesEnable = true;
			continue;
		}
		if (match_str == "don't()") {
			currentState->multipliesEnable = false;
			continue;
		}
		if (currentState->multipliesEnable) {
			currentState->currentValue += stol(match[1]) * stol(match[2]);
		}
	}
}