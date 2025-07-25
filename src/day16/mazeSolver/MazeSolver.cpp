#include "MazeSolver.h"
#include "Spot.h"

#include <map>
#include <deque>

MazeSolver::MazeSolver(Point2D start, Point2D end, vector<string> maze, Point2D initialDir) : AMazeSolver(start, end, maze, initialDir) {
}

MazeSolver::~MazeSolver() {
}

int_least64_t MazeSolver::solve() {
    Spot initialSpot = Spot(start, initialDir);

    map<Point2D, Spot> seen;
    Spot minSpot = Spot(Point2D(-1, -1), Point2D(-1, -1));
    minSpot.score = INT_LEAST64_MAX;

    deque<Spot> queue = deque<Spot> { initialSpot };
	
    while (!queue.empty()) {
        Spot currentSpot = queue.front();
        queue.pop_front();
        bool goToNext = false;

        if (currentSpot.getCoord() == end) {
            if (minSpot.score>currentSpot.score) {
                minSpot = currentSpot;
            }
        } else {
            Point2D key = currentSpot.getCoord();
            if (!seen.contains(key)) {
                goToNext = true;
                seen[key] = currentSpot;
            } else if (seen[key].score > currentSpot.score) {
                goToNext = true;
                seen[key] = currentSpot;
            } else if (seen[key].score == currentSpot.score) {
                goToNext = true;
            }
            if (goToNext) {
                for (Point2D nextDir : directions) {
                    if (nextDir + currentSpot.getDir() != Point2DDirection::Origin) {
                        Point2D it = currentSpot.getCoord() + nextDir;
                        if (isValidMove(it)) {
                            Spot nextSpot = Spot(it, nextDir);
                            nextSpot.score = currentSpot.score + getCost(currentSpot.getDir(), nextDir);
							if (minSpot.score > nextSpot.score) {
                                queue.push_back(nextSpot);
                            }
                        }
                    }
                }
            }
        }
    }
    return minSpot.score;
}
