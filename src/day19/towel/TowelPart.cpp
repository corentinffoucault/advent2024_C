#include "TowelPart.h"

TowelPart::TowelPart(char currentVal) : currentVal(currentVal) {
}

TowelPart::TowelPart() {
	currentVal = ' ';
}

TowelPart::~TowelPart() {
}

vector<string> TowelPart::getPossibleTowelRemovingTowelPart(string towel) {
    vector<string> reminder;
    if (isFinal) {
        reminder.push_back(towel);
    }
    if (towel.size() == 0) {
        return reminder;
    }
    char firstChar = towel[0];
    if (currentVal == ' ' && !nextVals.contains(firstChar)) {
        //println(towel);
    }
    if (nextVals.contains(firstChar)) {
        auto a = nextVals[firstChar].getPossibleTowelRemovingTowelPart(towel.substr(1));
        reminder.insert(reminder.begin(), a.begin(), a.end());
    }
    return reminder;
}

void TowelPart::addTowelPart(string towel) {
    if (towel.size() == 0) {
        isFinal = true;
        return;
    }
    char firstChar = towel[0];
    if (!nextVals.contains(firstChar)) {
        nextVals[firstChar] = TowelPart(firstChar);
    }
    nextVals[firstChar].addTowelPart(towel.substr(1));
}