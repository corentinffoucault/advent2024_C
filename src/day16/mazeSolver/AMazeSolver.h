#ifndef AMAZESOLVER_H_  
#define AMAZESOLVER_H_  

#include <cstdint>
#include <vector>

#include "../../../lib/Point2D/Point2D.h"

class AMazeSolver {
   public:  
       AMazeSolver(Point2D start, Point2D end, vector<string> maze, Point2D initialDir = Point2D(0, 0));
       virtual int_least64_t solve();
       ~AMazeSolver();
protected:
    Point2D size;
    int_least64_t getCost(Point2D currentDirection, Point2D nextDirection);
    bool isValidMove(Point2D point);
       Point2D start;
       Point2D end;
       Point2D initialDir;
       vector<Point2D> directions = {
           Point2DDirection::South,
           Point2DDirection::North,
           Point2DDirection::East,
           Point2DDirection::West
       };
   private:
       bool isValidZone(Point2D point);
       bool inRange(Point2D point);
       vector<string> maze;
};
#endif /* AMAZESOLVER_H_ */