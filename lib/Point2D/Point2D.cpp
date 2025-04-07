
#include "Point2D.h"

Point2D::Point2D(int _x, int _y) {
	x = _x;
	y = _y;
}

int Point2D::getX() {
	return this->x;
}

int Point2D::getY() {
	return this->y;
}

Point2D Point2D::operator+(const Point2D& other) const {
	return Point2D(this->x + other.x, this->y + other.y);
}

Point2D Point2D::operator-(const Point2D& other) const {
	return Point2D(this->x - other.x, this->y - other.y);
}

Point2D Point2D::operator*(const int value) const {
	return Point2D(this->x * value, this->y * value);
}

bool Point2D::operator<(const Point2D& other) const {
	return this->x < other.x || this->x == other.x && this->y < other.y;
}

Point2D::~Point2D() {
}

string Point2D::toString() {
	return "$x $y";
}

const Point2D Point2DDirection::North = Point2D(0, -1);
const Point2D Point2DDirection::South = Point2D(0, 1);
const Point2D Point2DDirection::East = Point2D(-1, 0);
const Point2D Point2DDirection::West = Point2D(1, 0);
const Point2D Point2DDirection::Origin = Point2D(0, 0);