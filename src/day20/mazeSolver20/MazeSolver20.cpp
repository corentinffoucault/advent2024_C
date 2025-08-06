#include "MazeSolver20.h"

#include <deque>

MazeSolver20::MazeSolver20(Point2D start, Point2D end, vector<string> maze, Point2D initialDir) : start(start), end(end), maze(maze), initialDir(initialDir) {
	size = Point2D(maze[0].size(), maze.size());
}

MazeSolver20::~MazeSolver20() {
}

map<Point2D, int> MazeSolver20::solve() {

	map<Point2D, int> seen;
	int index = 0;
	deque<Point2D> queue = deque<Point2D>{ start };

	while (!queue.empty()) {
		Point2D currentPoint = queue.front();
		queue.pop_front();

		if (!seen.contains(currentPoint)) {
			seen[currentPoint] = index++;
			if (currentPoint == end) {
				return seen;
			}
			for (Point2D nextDir : directions) {
				Point2D nextPoint = currentPoint + nextDir;
				if (nextPoint != Point2DDirection::Origin && isValidMove(nextPoint)) {
					queue.push_back(nextPoint);
				}
			}
		}
	}
	return seen;
}

bool MazeSolver20::inRange(Point2D point) {
	return point.getX() >= 0 && point.getX() < size.getX() && point.getY() >= 0 && point.getY() < size.getY();
}

bool MazeSolver20::isValidZone(Point2D point) {
	return maze[point.getY()][point.getX()] != '#';
}

bool MazeSolver20::isValidMove(Point2D point) {
	return inRange(point) && isValidZone(point);
}
