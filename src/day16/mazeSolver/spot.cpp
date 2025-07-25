#include <string>

#include "Spot.h"

Spot::Spot(Point2D coord, Point2D dir): coord(coord), dir(dir) {}

Spot::Spot() {
	coord = Point2D(0, 0);
	dir = Point2D(1, 0); // Default direction is East
}

Spot::~Spot() {
}

string Spot::getKey() {
	if (key.empty()) {
		key = coord.toString() + " " + dir.toString();
	}
   return key;
}
