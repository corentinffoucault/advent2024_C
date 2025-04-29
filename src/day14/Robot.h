#ifndef ROBOT_H_  
#define ROBOT_H_  
#include <vector>  
#include <memory>

#include "../../lib/Point2D/Point2D.h"

using namespace std;

class Robot {
public:
    Robot(Point2D _initialPoint, Point2D _speed);
    Point2D solve(Point2D size);
	Point2D getCurrentPoint();
	int getQuadrant(Point2D pos, Point2D size);
private: 
	Point2D initialPoint;
	Point2D currentPoint;
	Point2D speed;
	int floormod(int a, int b);
};
#endif