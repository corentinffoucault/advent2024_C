#include <cmath>
#include <cstdint>
#include <map>
#include <set>

#include "../../../lib/Point2D/Point2D.h"
#include "AGarden.h"
#include "Garden.h"

Garden::Garden(map<char, set<Point2D>> _groupedFlowers) : AGarden(_groupedFlowers) {  
}

int_least64_t Garden::calculateFullCost() {
    int_least64_t result = 0;
	for (auto& [c, group] : groupedFlowers) {
		auto continuousGroup = splitFlowerInContinuousGroup(group);
		result += calculateForOneCategorie(c, continuousGroup);
	}
    return result;
}

int_least64_t Garden::calculateForOneCategorie(char categorie, set<set<Point2D>> continuousGroups) {
    int_least64_t result = 0;
    for (set<Point2D> continuousGroup : continuousGroups) {
        int_least64_t a = fenceSize(continuousGroup);
        result += continuousGroup.size() * a;
    }
    return result;
}

set<set<Point2D>> Garden::splitFlowerInContinuousGroup(set<Point2D> flowers) {
    set<set<Point2D>> groupedSeen;

    for (Point2D currentFlower : flowers) {
        set<set<Point2D>> contiguous;
        set<set<Point2D>> nonContiguous;
        for (set<Point2D> it : groupedSeen) {
            if (isContiguous(it, currentFlower)) {
                contiguous.insert(it);
            } else {
                nonContiguous.insert(it);
            }
        }
        nonContiguous.insert(fusionContiguous(contiguous, currentFlower));
        groupedSeen = nonContiguous;
    } 

    return groupedSeen;
}

int_least64_t Garden::fenceSize(set<Point2D> group) {
    map<char, set<Point2D>> fencesByDir{};
    fencesByDir['^'] = {};
    fencesByDir['>'] = {};
    fencesByDir['<'] = {};
    fencesByDir['v'] = {};
    for (Point2D flower : group) {
        nbFenceAroundFlower(group, flower, &fencesByDir);
    }

    int_least64_t res = 0L;
    for (auto& [c, value] : fencesByDir) {
        res += value.size();
    }

    return res;
}