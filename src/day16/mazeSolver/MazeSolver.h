#ifndef MAZESOLVER_H_  
#define MAZESOLVER_H_  

#include "AMazeSolver.h"
#include <vector>

class MazeSolver : public AMazeSolver {
   public:  
       MazeSolver(Point2D start, Point2D end, vector<string> maze, Point2D initialDir = Point2D(0, 0));
       int_least64_t solve() override;
       ~MazeSolver();
   private:  
};
#endif /* MAZESOLVER_H_ */