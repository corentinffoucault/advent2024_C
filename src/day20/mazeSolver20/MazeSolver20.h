#ifndef MAZESOLVER_20_H_  
#define MAZESOLVER_20_H_  

#include <cstdint>
#include <vector>
#include <map>

#include "../../../lib/Point2D/Point2D.h"

class MazeSolver20 {
   public:  
       MazeSolver20(Point2D start, Point2D end, vector<string> maze, Point2D initialDir = Point2D(0, 0));
       map<Point2D, int> solve();
       ~MazeSolver20();
private:
    Point2D size;
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
       bool isValidZone(Point2D point);
       bool inRange(Point2D point);
       vector<string> maze;
};
#endif /* MazeSolver_H_ */