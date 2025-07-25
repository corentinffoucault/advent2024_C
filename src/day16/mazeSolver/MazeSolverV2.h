#ifndef MAZESOLVERV2_H_  
#define MAZESOLVERV2_H_  

#include <map>
#include <set>
#include <vector>
#include <cstdint>

#include "Spot.h"
#include "AMazeSolver.h"

class MazeSolverV2Data {
   public:
       map<string, int_least64_t> seen;
       set<Point2D> valid;
};

class MazeSolverV2 : public AMazeSolver {
   public:  
       MazeSolverV2(Point2D start, Point2D end, vector<string> maze, Point2D initialDir = Point2D(0, 0), int_least64_t maxScore = 0);
       int_least64_t solve() override;
       ~MazeSolverV2();
   private:  
       bool recursiveSolve(Spot currentSpot, MazeSolverV2Data* data);
	   int_least64_t maxScore;
};
#endif /* MAZESOLVERV2_H_ */