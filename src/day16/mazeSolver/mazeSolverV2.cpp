#include <cstdint>
#include <map>

#include "MazeSolverV2.h"
#include "Spot.h"
#include "AMazeSolver.h"

MazeSolverV2::MazeSolverV2(Point2D start, Point2D end, vector<string> maze, Point2D initialDir, int_least64_t maxScore) : AMazeSolver(start, end, maze, initialDir), maxScore(maxScore) {
}

MazeSolverV2::~MazeSolverV2() {
}

int_least64_t MazeSolverV2::solve() {
    Spot initialSpot = Spot(start, initialDir);
    MazeSolverV2Data data;
    recursiveSolve(initialSpot, &data);
    return data.valid.size();
}

bool MazeSolverV2::recursiveSolve(Spot currentSpot, MazeSolverV2Data* data) {
    if (currentSpot.getCoord() == end) {
        data->valid.insert(currentSpot.getCoord());
        return true;
    }
    bool result = false;
    for (Point2D nextDir : directions) {
        if (nextDir + currentSpot.getDir() != Point2DDirection::Origin) {
            Point2D it = currentSpot.getCoord() + nextDir;
            if (isValidMove(it)) {
                Spot nextSpot = Spot(it, nextDir);
                nextSpot.score = currentSpot.score + getCost(currentSpot.getDir(), nextDir);
                if (!data->seen.contains(nextSpot.getKey()) || data->seen[nextSpot.getKey()] >= nextSpot.score) {
                    data->seen[nextSpot.getKey()] = nextSpot.score;
                    if (maxScore >= nextSpot.score) {
                        bool a = recursiveSolve(nextSpot, data);
                        if (a) {
                            data->valid.insert(currentSpot.getCoord());
                        }
                        result |= a;
                       
                    }
                }
            }
        }
    }
    return result;
}
