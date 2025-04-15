#ifndef MACHINE_H_  
#define MACHINE_H_  

#include <cstdint>

#include "../../lib/Point2D/Point2D.h"

using namespace std;

class Machine {
public:
    Machine(Point2D _buttonA, Point2D _buttonB, Point2D _prize);
    int_least64_t solveWithCramer(int_least64_t factor = 0);
private:     
	Point2D buttonA;
	Point2D buttonB;
	Point2D prize;
};
#endif