#include <cstdint>

#include "../../lib/Point2D/Point2D.h"
#include "Machine.h";

Machine::Machine(Point2D _buttonA, Point2D _buttonB, Point2D _prize) {
    this->buttonA = _buttonA;
    this->buttonB = _buttonB;
    this->prize = _prize;
}

int_least64_t Machine::solveWithCramer(int_least64_t factor) {
    int_least64_t prizeXBig = prize.getX() + factor;
    int_least64_t prizeYBig = prize.getY() + factor;
    int_least64_t det = buttonA.getX() * buttonB.getY() - buttonA.getY() * buttonB.getX();
    int_least64_t a = (prizeXBig * buttonB.getY() - prizeYBig * buttonB.getX()) / det;
    int_least64_t b = (buttonA.getX() * prizeYBig - buttonA.getY() * prizeXBig) / det;
    return buttonA.getX() * a + buttonB.getX() * b == prizeXBig && buttonA.getY() * a + buttonB.getY() * b == prizeYBig ? a * 3 + b : 0;
}