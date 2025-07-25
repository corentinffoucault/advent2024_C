#ifndef SPOT_H_  
#define SPOT_H_  

#include "../../../lib/Point2D/Point2D.h"  
#include <cstdint>
#include <string>  

using namespace std;  

class Spot {  
public:  
  Spot(Point2D coord, Point2D dir);  
  Spot();  
  ~Spot();
  string getKey();
  int_least64_t score = 0;
  Point2D getCoord() const {
	  return coord;
  }
  Point2D getDir() const {
	  return dir;
  }
private:  
  string key = "";
  Point2D coord;  
  Point2D dir;  
};  

#endif /* SPOT_H_ */