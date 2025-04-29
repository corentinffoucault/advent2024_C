#include <cmath>
#include <locale>

#include "../../lib/Point2D/Point2D.h"
#include "Robot.h";

Robot::Robot(Point2D _initialPoint, Point2D _speed) {
    this->initialPoint = _initialPoint;
    this->currentPoint = _initialPoint;
    this->speed = _speed;
}

Point2D Robot::solve(Point2D size) {
    this->currentPoint = Point2D(floormod(currentPoint.getX() + speed.getX(), size.getX()), floormod(currentPoint.getY() + speed.getY(), size.getY()));
    return this->currentPoint;
}

Point2D Robot::getCurrentPoint() {
    return currentPoint;
}

int Robot::getQuadrant(Point2D pos, Point2D size) {
    int x = pos.getX();
    int y = pos.getY();
    if (pos.getX() < floor(size.getX() / 2.)) {
        if (pos.getY() < floor(size.getY() / 2.)) {
            return 1;
        } else if (pos.getY() >= ceil(size.getY() / 2.)) {
            return 2;
        }
    } else if (pos.getX() >= ceil(size.getX() / 2.)) {
        if (pos.getY() < floor(size.getY() / 2.)) {
            return 3;
        } else if (pos.getY() >= ceil(size.getY() / 2.)) {
            return 4;
        }
    }
    return 0;
}

int Robot::floormod(int a, int b) {
    return ((a % b) + b) % b;
}