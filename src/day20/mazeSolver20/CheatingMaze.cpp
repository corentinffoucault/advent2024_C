#include "CheatingMaze.h"
#include <cmath>


CheatingMaze::CheatingMaze(int jumpSize): jumpSize(jumpSize) {

}

CheatingMaze::~CheatingMaze() {

}

int CheatingMaze::cheat(map<Point2D, int> path) {
	int res = 0;
	set<Point2D> jumps = getAllJumps();
	for (const auto& [currentPoint, value] : path) {
		for (Point2D jump : jumps) {
			Point2D nextPoint = currentPoint + jump;
			if (path.contains(nextPoint)) {
				int currentVal = path[nextPoint];
				int a = getNbCase(jump);
				int currentDist = currentVal - value - getNbCase(jump);
				if (currentDist >= 100) {
					res++;
				}
			}
		}
	}
	return res;
}

set<Point2D> CheatingMaze::getAllJumps() {
	set<Point2D> jumps;
	for (int i = 0; i <= jumpSize; i++) {
		for (int j = 0; j <= jumpSize - i; j++) {
			if (i > 1 || j > 1) {
				jumps.insert(Point2D(i, j));
				jumps.insert(Point2D(-i, j));
				jumps.insert(Point2D(i, -j));
				jumps.insert(Point2D(-i, -j));
			}
		}
	}
	return jumps;
}

int CheatingMaze::getNbCase(Point2D point) {
	return abs(point.getX()) + abs(point.getY());
}