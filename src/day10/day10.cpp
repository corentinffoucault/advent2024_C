#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "day10.h"
#include "../../lib/Point2D/Point2D.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day10::day10(fs::path _currentPath) : ADay(_currentPath) {

}

day10::~day10() {
}

string day10::run() {
    Topographic topo = createData();
	return to_string(topo.findAllFullPathFromAllSource());
}

string day10::run2() {
    Topographic topo = createData();
    return to_string(topo.findAllFullPathFromAllSourceV2());
}

Topographic day10::createData() {
    vector<Point2D> zeros;
    vector<vector<int>> map;
	ifstream file_content(currentPath);
    int y = 0;
    string line;
    while (getline(file_content, line)) {
		vector<int> lineVector(line.length());
        int x = 0;
        for (char& c : line) {
            stringstream tmp;
            int currentValue;
            tmp << c;
            tmp >> currentValue;
            lineVector[x] = currentValue;
			if (currentValue == 0) {
				zeros.push_back(Point2D(x, y));
			}
            x++;
        }
		map.push_back(lineVector);
        y++;
    }
	return Topographic(zeros, map);
}