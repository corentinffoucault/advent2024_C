#ifndef MazeSolver18_H_  
#define MazeSolver18_H_  

#include <cstdint>
#include <vector>
#include <set>

#include "../../../lib/Point2D/Point2D.h"

class MazeSolver18 {
   public:  
       MazeSolver18(Point2D start, Point2D end, Point2D size);
       virtual size_t solve(vector<Point2D> corrupted);
       ~MazeSolver18();
protected:
       Point2D start;
       Point2D end;
       Point2D size;
       vector<Point2D> directions = {
           Point2DDirection::South,
           Point2DDirection::North,
           Point2DDirection::East,
           Point2DDirection::West
       };
       bool inRange(Point2D point);
       size_t run(vector<Point2D> corrupted);
};
#endif /* MazeSolver18_H_ */