#include "Computer23.h"

#include <algorithm>
#include <iterator>

Computer23::Computer23(string name): name(name) {
}

Computer23::~Computer23() {
}

void Computer23::addComputer(string computer) {
	connectedComputer.insert(computer);
}

unordered_set<string> Computer23::intersectValue(unordered_set<string> otherConnectedComputer) {
    unordered_set<string> result;
    unordered_set<string> smallest;
    unordered_set<string> biggest;
    
    if (otherConnectedComputer.size() > connectedComputer.size()) {
		smallest = connectedComputer;
		biggest = otherConnectedComputer;
    } else {
        biggest = connectedComputer;
        smallest = otherConnectedComputer;
    }
    for (string comp : smallest) {
        if (biggest.contains(comp)) {
            result.insert(comp);
        }
	}
    return result;
}

unordered_set<string> Computer23::values() {
    return connectedComputer;
}

string Computer23::toString() {
    return name;
}

int Computer23::size() {
    return connectedComputer.size();
}

bool Computer23::operator==(const Computer23& other) const {
    return this->name == other.name;
}

bool Computer23::operator<(const Computer23& other) const {
    return this->name < other.name;
}

string Computer23::getName() const {
    return name;
}