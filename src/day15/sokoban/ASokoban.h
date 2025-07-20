#ifndef ASOKOBAN_H_  
#define ASOKOBAN_H_  
#include <cstdint>
#include <string>
#include <vector>  
#include <utility>

#include "../../../lib/Point2D/Point2D.h"

using namespace std;

class ASokoban {
public:
	ASokoban(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements);
	int_least64_t getGpsSum();
	virtual void doMovements();
protected: 
	Point2D initialPoint;
	vector<string> fullMap;
	vector<Point2D> movements;
	int_least64_t gps(int x, int y);
};

#endif