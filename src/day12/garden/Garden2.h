#ifndef GARDEN2_H_  
#define GARDEN2_H_  

#include <map>
#include <set> 
#include <cstdint>

#include "../../../lib/Point2D/Point2D.h"
#include "AGarden.h"

using namespace std;

class Garden2 : public AGarden {
public:
    Garden2(map<char, set<Point2D>> _groupedFlowers);
    int_least64_t calculateFullCost() override;
private: 
    int_least64_t calculateForOneCategorie(char cat, set<set<Point2D>> continuousGroups);
    set<set<Point2D>> splitFlowerInContinuousGroup(set<Point2D> flowers);
    int_least64_t fenceSize(char cat, set<Point2D> group);
    size_t getGroupSize(char cat, char dir, set<Point2D> flowers);
};
#endif