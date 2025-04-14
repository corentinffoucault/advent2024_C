#include "AGarden.h"
#include <cmath>
#include <cstdint>
#include <set>
#include <map>

#include "Garden.h"
#include <iostream>

AGarden::AGarden(map<char, set<Point2D>> _groupedFlowers) {
    this->groupedFlowers = _groupedFlowers;
}

int_least64_t AGarden::calculateFullCost() {
	cout << "Calculating full cost" << endl << flush;
    return int_least64_t();
}

set<Point2D> AGarden::fusionContiguous(set<set<Point2D>> contiguous, Point2D currentFlower) {
    set<Point2D> result = { currentFlower };
    for (set<Point2D> it : contiguous) {
        result.insert(it.begin(), it.end());
    }
    return result;
}

bool AGarden::isContiguous(set<Point2D> group, Point2D currentFlower) {
    for (Point2D it : group) {
        if (abs(it.getX() - currentFlower.getX()) == 1 && it.getY() - currentFlower.getY() == 0 ||
            it.getX() - currentFlower.getX() == 0 && abs(it.getY() - currentFlower.getY()) == 1) {
            return true;
        }
    }
    return false;
}

int_least64_t AGarden::nbFenceAroundFlower(set<Point2D> group, Point2D flower, map<char, set<Point2D>>* fencesByDir) {
    if (!group.contains(flower + Point2D(1, 0))) {
        fencesByDir->at('>').insert(flower + Point2D(1, 0));
    }
    if (!group.contains(flower + Point2D(-1, 0))) {
        fencesByDir->at('<').insert(flower + Point2D(-1, 0));
    }
    if (!group.contains(flower + Point2D(0, 1))) {
        fencesByDir->at('v').insert(flower + Point2D(0, 1));
    }
    if (!group.contains(flower + Point2D(0, -1))) {
        fencesByDir->at('^').insert(flower + Point2D(0, -1));
    }
    return 0L;
}