#include <deque>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include "../../../lib/Point2D/Point2D.h"
#include "ASokoban.h"
#include "Sokoban2.h";

Sokoban2::Sokoban2(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements) : ASokoban(_initialPoint, _fullMap, _movements) {
}

void Sokoban2::doMovements() {
   extends();
   Point2D place = initialPoint;  
   for (Point2D movement : movements) {  
       Point2D nextPosition = place + movement;  
       char nextChar = fullMap[nextPosition.getY()][nextPosition.getX()];  
       switch (nextChar) {  
       case '[':  
       case 'O':  
       case ']': {  
           vector<pair<Point2D, Point2D>> subMove = analysePush(nextPosition, movement);
		   if (!subMove.empty()) {
			   for (pair<Point2D, Point2D> move : subMove) {
				   Point2D from = move.first;
				   Point2D to = move.second;
				   fullMap[to.getY()][to.getX()] = fullMap[from.getY()][from.getX()];
				   fullMap[from.getY()][from.getX()] = '.';
			   }
			   fullMap[place.getY()][place.getX()] = '.';
			   place = nextPosition;
			   fullMap[nextPosition.getY()][nextPosition.getX()] = '@';
		   }
           break;  
       }  
       case '#':  
           break;  
       default:
		   fullMap[place.getY()][place.getX()] = '.';
		   place = nextPosition;
		   fullMap[nextPosition.getY()][nextPosition.getX()] = '@';
           break;  
       }  
   }
}

void Sokoban2::extends() {
	size_t lineIndex = 0;
    for (string line : fullMap) {
		string newLine = "";
		for (char item : line) {
			newLine += extendsChar(item);
		}
		fullMap[lineIndex++] = newLine;
    }
	initialPoint = Point2D(initialPoint.getX() * 2, initialPoint.getY());
}

string Sokoban2::extendsChar(char item) {
	auto it = convertionMap.find(item);
	if (it != convertionMap.end()) {
		return it->second;
	}
	throw invalid_argument("Invalid direction character");
}

vector<pair<Point2D, Point2D>> Sokoban2::analysePush(Point2D position, Point2D direction) {
	vector<pair<Point2D, Point2D>> safePushes;
	set<Point2D> seen;
	deque<Point2D> queue;
	queue.push_back(position);

	while (!queue.empty()) {
		Point2D thisPosition = queue.front();
		if (!seen.contains(thisPosition)) {
			seen.insert(thisPosition);
			if (direction == Point2DDirection::South || direction == Point2DDirection::North) {
				switch (fullMap[thisPosition.getY()][thisPosition.getX()]) {
				case ']':
					queue.push_back(thisPosition + Point2DDirection::East);
					break;
				case '[':
					queue.push_back(thisPosition + Point2DDirection::West);
					break;
				}
			}
			Point2D nextPosition = thisPosition + direction;
			switch (fullMap[nextPosition.getY()][nextPosition.getX()]) {
			case '#':
				return {};
			case ']':
			case 'O':
			case '[':
				queue.push_back(nextPosition);
				break;
			}
			safePushes.push_back(make_pair(thisPosition, nextPosition));
		}
		queue.pop_front();
	}
	reverse(safePushes.begin(), safePushes.end());
	return safePushes;
}