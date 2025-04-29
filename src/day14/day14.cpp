#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <iostream>
#include <regex>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "day14.h"
#include "Robot.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day14::day14(fs::path _currentPath) : ADay(_currentPath) {

}

day14::~day14() {
}

string day14::run() {
	return to_string(printFile());
}

string day14::run2() {
    return to_string(printFile());
}

int day14::printFile() {
    std::ofstream result("file.txt");

    Point2D size = Point2D(101, 103);
    vector<Robot> robots = createData(size);

    vector<int> quadrants;

    for (int i = 0; i < 10000; i++) {
        vector<string> map = createMap(size);

        for(Robot robot: robots) {
            map[robot.getCurrentPoint().getY()][robot.getCurrentPoint().getX()] = '1';
        }

        for (string line : map) {
            if (line.find("1111111111111111111111111111111") != string::npos) {
                cout << format("创创创创创创创创创' {}", i) << endl << flush;
            }
            result << line << endl;
        }

        quadrants = { 0, 0, 0, 0, 0 };

        for (Robot& robot : robots) {
            Point2D currentPoint = robot.solve(size);
            quadrants[robot.getQuadrant(currentPoint, size)]++;
        }

        result << endl << flush;
    }
    
    result.close();
    int acc = 1;
    for (int i = 1; i < quadrants.size(); i++) {
        acc = acc * quadrants[i];
	}
    return acc;
}

vector<string> day14::createMap(Point2D size) {
    vector<string> map;
    for (int i = 0; i < size.getY(); i++) {
        map.push_back(string(size.getX(), '.'));
    }
    return map;
}

vector<Robot> day14::createData(Point2D size) {
    vector<Robot> robots;
	ifstream file_content(currentPath);
    string line;
    while (getline(file_content, line)) {
        robots.push_back(extractInfo(line, size));
    }
    return robots;
}

Robot day14::extractInfo(string line, Point2D size) {
    smatch m;
    regex_match(line, m, pointFinder);
    int x0 = 0;
    int y0 = 0;
    int cx = 0;
    int cy = 0;
    stringstream tmp_x0;
    tmp_x0 << m.str(1);
    tmp_x0 >> x0;
    stringstream tmp_y0;
    tmp_y0 << m.str(2);
    tmp_y0 >> y0;
    stringstream tmp_cx;
    tmp_cx << m.str(3);
    tmp_cx >> cx;
    stringstream tmp_cy;
    tmp_cy << m.str(4);
    tmp_cy >> cy;
    return Robot(Point2D(x0, y0), Point2D(cx, cy));
}