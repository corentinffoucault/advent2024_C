#include <filesystem>
#include <fstream>
#include <set>
#include <string>
#include <tuple>

#include "day6.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day6::day6(fs::path _currentPath) : ADay(_currentPath) {

}

day6::~day6() {
}

string day6::run() {
	day6Data data = createData();
	set<Point2D> firstSeen = initialRun(data);
	return to_string(firstSeen.size());
}

string day6::run2() {
	day6Data data = createData();
	set<Point2D> firstSeen = initialRun(data);
	int nbLoop = 0;
	for (auto it : firstSeen) {
		// cout << data.matrix[it.getY()][it.getX()] << endl;
		data.matrix[it.getY()][it.getX()] = '#';
		if (move(data)) {
			nbLoop++;
		}
		data.matrix[it.getY()][it.getX()] = '.';
	}
	return to_string(nbLoop);
}

day6Data day6::createData() {
	day6Data data;
	string line;
	ifstream file_content(currentPath);
	int lineIndex = 0;
	while (getline(file_content, line)) {
		data.matrix.push_back(line);
		size_t initialCoordIndex = line.find('^');
		if (initialCoordIndex !=  line.npos) {
			data.initialCoord = Point2D(initialCoordIndex, lineIndex);
		}
		lineIndex++;
	}
	return data;
}

set<Point2D> day6::initialRun(day6Data data) {
	Point2D dir = Point2D(0, -1);
	set<Point2D> seenCase;
	Point2D coord = data.initialCoord;
	seenCase.insert(coord);
	Point2D nextCoord = coord + dir;
	while (nextCoord.getX() < data.matrix[0].length() && nextCoord.getX() > -1 && nextCoord.getY() < data.matrix.size() && nextCoord.getY() > -1) {
		if (data.matrix[nextCoord.getY()][nextCoord.getX()] == '#') {
			dir = rotate(dir);
		} else {
			coord = nextCoord;
			seenCase.insert(coord);
		}
		nextCoord = coord + dir;
	}
	return seenCase;
}

Point2D day6::rotate(Point2D dir) {
	Point2D tmp = Point2DDirection::North;
	if (dir.getY() == 1) {
		tmp = Point2D(-1, 0);
	} else if (dir.getY() == -1) {
		tmp = Point2D(1, 0);
	} else if (dir.getX() == 1) {
		tmp = Point2D(0, 1);
	} else {
		tmp = Point2D(0, -1);
	}
	return tmp;
}

string day6::getDir(Point2D dir) {
	string tmp;
	if (dir.getY() == 1) {
		return "u";
	} else if (dir.getY() == -1) {
		return "^";
	} else if (dir.getX() == 1) {
		return ">";
	} else {
		return "<";
	}
	return tmp;
}

bool day6::move(day6Data data) {
	Point2D dir = Point2D(0, -1);
	set<tuple<Point2D, Point2D>> seenCase;
	Point2D coord = data.initialCoord;
	seenCase.insert(make_tuple(coord, dir));
	Point2D nextCoord = coord + dir;
	while (nextCoord.getX() < data.matrix[0].length() && nextCoord.getX() > -1 && nextCoord.getY() < data.matrix.size() && nextCoord.getY() > -1) {
		if (data.matrix[nextCoord.getY()][nextCoord.getX()] == '#') {
			dir = rotate(dir);
		} else {
			coord = nextCoord;
			tuple<Point2D, Point2D> tmp = make_tuple(coord, dir);
			if (seenCase.contains(tmp)) {
				return true;
			}
			seenCase.insert(tmp);
		}
		nextCoord = coord + dir;
	};
	return false;
}