#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "day16.h"
#include "mazeSolver/MazeSolver.h"
#include "mazeSolver/MazeSolverV2.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day16::day16(fs::path _currentPath) : ADay(_currentPath) {

}

day16::~day16() {
}

string day16::run() {
    day16Data data = createData();
    MazeSolver mazeSolver = MazeSolver(data.start, data.end, data.maze);
    int_least64_t a = mazeSolver.solve();
    return to_string(a);
}

string day16::run2() {
    day16Data data = createData();
    MazeSolver mazeSolver = MazeSolver(data.start, data.end, data.maze);
    int_least64_t maxScore = mazeSolver.solve();

    MazeSolverV2 mazeSolverV2 = MazeSolverV2(data.start, data.end, data.maze, Point2D(0, 0), maxScore);
    return to_string(mazeSolverV2.solve());
}

day16Data day16::createData() {
    day16Data data;

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