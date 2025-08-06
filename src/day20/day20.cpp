#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "day20.h"
#include "mazeSolver20/MazeSolver20.h"
#include "mazeSolver20/CheatingMaze.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day20::day20(fs::path _currentPath) : ADay(_currentPath) {

}

day20::~day20() {
}

string day20::run() {
    day20Data data = createData();
    MazeSolver20 mazeSolver = MazeSolver20(data.start, data.end, data.maze);
    map<Point2D, int> path = mazeSolver.solve();
    CheatingMaze cheatingMaze = CheatingMaze(2);
    return to_string(cheatingMaze.cheat(path));
}

string day20::run2() {
    day20Data data = createData();
    MazeSolver20 mazeSolver = MazeSolver20(data.start, data.end, data.maze);
    map<Point2D, int> path = mazeSolver.solve();
    CheatingMaze cheatingMaze = CheatingMaze(20);
    return to_string(cheatingMaze.cheat(path));
}

day20Data day20::createData() {
    day20Data data;

    ifstream file_content(currentPath);
    string line;
    size_t lineIndex = 0;

    while (getline(file_content, line)) {
		size_t indexOfE = line.find('E');
        if (indexOfE != string::npos) {
            data.end = Point2D(indexOfE, lineIndex);
        }
		size_t indexOfS = line.find('S');
        if (indexOfS != string::npos) {
            data.start = Point2D(indexOfS, lineIndex);
        }
        data.maze.push_back(line);
        lineIndex++;
    }
    return data;
}