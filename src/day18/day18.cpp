#include <filesystem>
#include <fstream>
#include <regex>

#include "../ADay/ADay.h"
#include "day18.h"
#include "mazeSolver18/MazeSolver18.h"
#include "mazeSolver18/MazeSolver18V2.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day18::day18(fs::path _currentPath) : ADay(_currentPath) {

}

day18::~day18() {
}

string day18::run() {
    MazeSolver18 maze = MazeSolver18(Point2D(0, 0), Point2D(70, 70), Point2D(71, 71));
    vector<Point2D> corrupted = createData();
    auto midIt = next(corrupted.begin(), 1024);
    vector<Point2D> sv(corrupted.begin(), midIt);
	return to_string(maze.solve(sv));
}

string day18::run2() {
    MazeSolver18V2 maze = MazeSolver18V2(Point2D(0, 0), Point2D(70, 70), Point2D(71, 71));
    vector<Point2D> corrupted = createData();
    return corrupted[maze.solve(corrupted)].toString();
}

vector<Point2D> day18::createData() {
    ifstream file_content(currentPath);
    string line;
    size_t lineIndex = 0;
    vector<Point2D> corrupted;

    while (getline(file_content, line)) {
        smatch m;
        regex_match(line, m, pointFinder);
        stringstream tmp_x;
        int x = 0;
        int y = 0;
        tmp_x << m.str(1);
        tmp_x >> x;
        stringstream tmp_y;
        tmp_y << m.str(2);
        tmp_y >> y;
        corrupted.push_back(Point2D(x, y));
    }
    return corrupted;
}