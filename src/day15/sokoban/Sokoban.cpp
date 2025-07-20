#include "Sokoban.h"
#include <deque>
#include <string>
#include <vector>

#include "../../../lib/Point2D/Point2D.h"
#include "Sokoban.h";


Sokoban::Sokoban(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements) : ASokoban(_initialPoint, _fullMap, _movements) {
}

void Sokoban::doMovements() {  
   Point2D place = initialPoint;  
   for (Point2D movement : movements) {
       Point2D nextPosition = place + movement;  
       char nextChar = fullMap[nextPosition.getY()][nextPosition.getX()];  
       switch (nextChar) {  
       case 'O': {  
           vector<pair<Point2D, Point2D>> subMove = analysePush(nextPosition, movement);
		   if (!subMove.empty()) {
			   doPush(subMove);
			   place = nextPosition;
		   }
           break;  
       }  
       case '#':  
           break;  
       default:
		   place = nextPosition;
           break;  
       }  
   }  
}

void Sokoban::doPush(vector<pair<Point2D, Point2D>> &subMove) {
	for (pair<Point2D, Point2D> move : subMove) {
		Point2D from = move.first;
		Point2D to = move.second;
		fullMap[to.getY()][to.getX()] = fullMap[from.getY()][from.getX()];
		fullMap[from.getY()][from.getX()] = '.';
	}
}

vector<pair<Point2D, Point2D>> Sokoban::analysePush(Point2D position, Point2D direction) {
	vector<pair<Point2D, Point2D>> safePushes;

	while (fullMap[position.getY()][position.getX()] == 'O') {
		Point2D next = position + direction;
		safePushes.push_back(make_pair(position, next));
		position = next;
	}
	if (fullMap[position.getY()][position.getX()] == '#') {
		return {};
	}
	reverse(safePushes.begin(), safePushes.end());
	return safePushes;
}