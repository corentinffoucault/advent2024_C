#include <filesystem>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <string>

#include "../../lib/Point2D/Point2D.h"
#include "day8.h"
#include <iostream>

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day8::day8(fs::path _currentPath) : ADay(_currentPath) {

}

day8::~day8() {
}

string day8::run() {
	day8Data data = createData();
    map<char, vector<Point2D>> parsedData = parseGrid(data);
	return to_string(countAntiNodes1(parsedData, data));
}

string day8::run2() {
	day8Data data = createData();
    map<char, vector<Point2D>> parsedData = parseGrid(data);
    return to_string(countAntiNodes2(parsedData, data));
}

day8Data day8::createData() {
	day8Data data;
	string line;
	ifstream file_content(currentPath);
	while (getline(file_content, line)) {
		data.matrix.push_back(line);
	}
	data.x_size = data.matrix[0].length();
	data.y_size = data.matrix.size();
	return data;
}

bool day8::isOnGrid(Point2D point, day8Data data) {
    return point.getY() < data.y_size && point.getY() >-1 && point.getX() < data.x_size && point.getX() >-1;
}

bool day8::isNotAntenna(Point2D point, day8Data data) {
    return data.matrix[point.getY()][point.getY()] == '.';
}

int day8::countAntiNodes1(map<char, vector<Point2D>> groupedAntenna, day8Data data) {
    set<Point2D> uniqueAntiNode;
    for(auto const& [key, antennas]: groupedAntenna) {
        for (size_t indexToIgnore = 0; indexToIgnore < antennas.size(); indexToIgnore++) {
			Point2D antennaToCheck = antennas[indexToIgnore];
            for (size_t currentIndex = 0; currentIndex < antennas.size(); currentIndex++) {
                if (currentIndex == indexToIgnore) {
                    continue;
                }
                Point2D antennaToCompare = antennas[currentIndex];
                set<Point2D> tmp = antiNodesForPart1(antennaToCheck, antennaToCompare, antennaToCheck - antennaToCompare, data);
                uniqueAntiNode.insert(tmp.begin(), tmp.end());
            }
        }
    }
    /*for (Point2D p : uniqueAntiNode) {
        cout << p.toString() << endl << flush;
    }*/
    return uniqueAntiNode.size();
}

int day8::countAntiNodes2(map<char, vector<Point2D>> groupedAntenna, day8Data data) {
    set<Point2D> uniqueAntiNode;
    for (auto const& [key, antennas] : groupedAntenna) {
        for (size_t indexToIgnore = 0; indexToIgnore < antennas.size(); indexToIgnore++) {
            Point2D antennaToCheck = antennas[indexToIgnore];
            for (size_t currentIndex = 0; currentIndex < antennas.size(); currentIndex++) {
                if (currentIndex == indexToIgnore) {
                    continue;
                }
                Point2D antennaToCompare = antennas[currentIndex];
                set<Point2D> tmp = antiNodesForPart2(antennaToCheck, antennaToCheck - antennaToCompare, data);
                uniqueAntiNode.insert(tmp.begin(), tmp.end());
            }
        }
    }
    return uniqueAntiNode.size();
}

set<Point2D> day8::antiNodesForPart1(Point2D a, Point2D b, Point2D diff, day8Data data) {
    set<Point2D> antiNodeSet;
    Point2D *antiNode1;
	Point2D *antiNode2;
    Point2D sum = a + diff;
    Point2D sub = b - diff;
    antiNode1 = &sum;
    antiNode2 = &sub;
    if (isOnGrid(*antiNode1, data)) {
        antiNodeSet.insert(*antiNode1);
    }
    if (isOnGrid(*antiNode2, data)) {
        antiNodeSet.insert(*antiNode2);
    }
    return antiNodeSet;
}

set<Point2D> day8::antiNodesForPart2(Point2D a, Point2D diff, day8Data data) {
    set<Point2D> antiNodeSet;
    Point2D currentNode = a;
    while (isOnGrid(currentNode, data)) {
        antiNodeSet.insert(currentNode);
        currentNode = currentNode - diff;
    }
    currentNode = a;
    while (isOnGrid(currentNode, data)) {
        antiNodeSet.insert(currentNode);
        currentNode = currentNode + diff;
    }

    return antiNodeSet;
}

map<char, vector<Point2D>> day8::parseGrid(day8Data data) {
    map<char, vector<Point2D>> antennas;
    for (size_t y = 0; y < data.y_size; y++) {
        for (size_t x = 0; x < data.x_size; x++) {
			char c = data.matrix[y][x];
			if (c != '.') {
				if (!antennas.contains(c)) {
                    antennas.emplace(c, vector<Point2D>());
				}
				antennas[c].push_back(Point2D(x, y));
			}
        }
    }
    return antennas;
}