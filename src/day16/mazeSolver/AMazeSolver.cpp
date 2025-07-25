#include "AMazeSolver.h"

AMazeSolver::AMazeSolver(Point2D start, Point2D end, vector<string> maze, Point2D initialDir) : start(start), end(end), maze(maze), initialDir(initialDir) {
	size = Point2D(maze[0].size(), maze.size());
}

AMazeSolver::~AMazeSolver() {
}

int_least64_t AMazeSolver::getCost(Point2D currentDirection, Point2D nextDirection) {
    if (currentDirection == nextDirection) {
        return 1;
    }
    return 1001;
}

int_least64_t AMazeSolver::solve() {
	return 0; // This method should be overridden in derived classes
}

bool AMazeSolver::inRange(Point2D point) {
    return point.getX() >= 0 && point.getX() < size.getX() && point.getY() >= 0 && point.getY() < size.getY();
}

bool AMazeSolver::isValidZone(Point2D point) {
    return maze[point.getY()][point.getX()] != '#';
}

bool AMazeSolver::isValidMove(Point2D point) {
	return inRange(point) && isValidZone(point);
}
