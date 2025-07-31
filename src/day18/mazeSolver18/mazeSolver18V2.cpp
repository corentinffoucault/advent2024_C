#include "MazeSolver18V2.h"
#include "MazeSolver18.h"

MazeSolver18V2::MazeSolver18V2(Point2D start, Point2D end, Point2D size) : MazeSolver18(start, end, size) {
}

MazeSolver18V2::~MazeSolver18V2() {
}

size_t MazeSolver18V2::solve(vector<Point2D> corrupted) {
    return dicotomie(corrupted);
}

size_t MazeSolver18V2::dicotomie(vector<Point2D> corrupted) {
    int min = 0;
    size_t max = corrupted.size();
    size_t firstFind = 0;
    while (min <= max) {
        size_t mid = (min + max) / 2;

        auto midIt = next(corrupted.begin(), mid+1);

        vector<Point2D> sv(corrupted.begin(), midIt);
        if (run(sv) == 0) {
            firstFind = mid;
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return firstFind;
}
