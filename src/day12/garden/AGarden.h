#ifndef AGARDEN_H_  
#define AGARDEN_H_  

#include <map>
#include <set> 
#include <cstdint>

#include "../../../lib/Point2D/Point2D.h"

using namespace std;

class AGarden {
public:
    AGarden(map<char, set<Point2D>> _groupedFlowers);
    virtual int_least64_t calculateFullCost();
protected: 
    map<char, set<Point2D>> groupedFlowers;
    set<Point2D> fusionContiguous(set<set<Point2D>> contiguous, Point2D currentFlower);
    bool isContiguous(set<Point2D> group, Point2D currentFlower);
    int_least64_t fenceSize(set<Point2D> group);
    int_least64_t nbFenceAroundFlower(set<Point2D> group, Point2D flower, map<char, set<Point2D>>* fencesByDir);
};
#endif