#include "MazeSolver18.h"

#include <deque>
#include <iostream>

MazeSolver18::MazeSolver18(Point2D start, Point2D end, Point2D size) : start(start), end(end), size(size) {
}

MazeSolver18::~MazeSolver18() {
}

bool MazeSolver18::inRange(Point2D point) {
	return point.getX() >= 0 && point.getX() < size.getX() && point.getY() >= 0 && point.getY() < size.getY();
}

size_t MazeSolver18::solve(vector<Point2D> corrupted) {
    return run(corrupted);
}

size_t MazeSolver18::run(vector<Point2D> corrupted) {
    deque<pair<Point2D, int>> queue{ make_pair(start, 0) };
    set<Point2D> seen;
    set<Point2D> corruptedSet(corrupted.begin(), corrupted.end());
    seen.insert(start);

    while (!queue.empty()) {
        pair<Point2D, int> curren_point = queue.front();
        queue.pop_front();
        if (curren_point.first == end) {
            return curren_point.second;
        } else {
            for (Point2D direction : directions) {
                Point2D nextPoint = curren_point.first + direction;
                if (inRange(nextPoint) && !corruptedSet.contains(nextPoint) && !seen.contains(nextPoint)) {
                    seen.insert(nextPoint);
                    queue.push_back(make_pair(nextPoint, curren_point.second + 1));
                }
            }
        }
    }
    return 0;
}