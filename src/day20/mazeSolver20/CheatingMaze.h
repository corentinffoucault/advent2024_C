#ifndef CHEATING_SOLVER_H_  
#define CHEATING_SOLVER_H_  

#include <map>
#include <set>

#include "../../../lib/Point2D/Point2D.h"

class CheatingMaze {
public:
    CheatingMaze(int jumpSize);
    int cheat(map<Point2D, int> path);
    ~CheatingMaze();
private:
    int jumpSize;
    set<Point2D> getAllJumps();
    int getNbCase(Point2D point);
};
#endif /* CHEATING_SOLVER_H_ */