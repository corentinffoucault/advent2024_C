#ifndef MazeSolver18V2_H_  
#define MazeSolver18V2_H_  

#include <map>
#include <set>
#include <cstdint>

#include "MazeSolver18.h"

class MazeSolver18V2Data {
   public:
       map<string, int_least64_t> seen;
       set<Point2D> valid;
};

class MazeSolver18V2 : public MazeSolver18 {
   public:  
       MazeSolver18V2(Point2D start, Point2D end, Point2D size);
       size_t solve(vector<Point2D> corrupted) override;
       ~MazeSolver18V2();
   private:
       size_t dicotomie(vector<Point2D> list);
};
#endif /* MazeSolver18V2_H_ */