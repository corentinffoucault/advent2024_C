#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "garden/Garden.h"
#include "garden/Garden2.h"
#include "day12.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day12::day12(fs::path _currentPath) : ADay(_currentPath) {

}

day12::~day12() {
}

string day12::run() {
    Garden garden = Garden(createData());
	return to_string(garden.calculateFullCost());
}

string day12::run2() {
    Garden2 garden = Garden2(createData());
    return to_string(garden.calculateFullCost());
}

map<char, set<Point2D>> day12::createData() {
    map<char, set<Point2D>> groupedFlowers;
	ifstream file_content(currentPath);
    string line;
    int y = 0;
    while (getline(file_content, line)) {
		vector<int> lineVector(line.length());
        int x = 0;
        for (char& c : line) {
           if (!groupedFlowers.contains(c)) {
               groupedFlowers[c] = set<Point2D>();
           }
           groupedFlowers[c].insert(Point2D(x, y));
           x++;
        }
        y++;
    }
	return groupedFlowers;
}