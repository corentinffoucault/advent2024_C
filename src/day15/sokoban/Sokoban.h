#ifndef SOKOBAN_H_  
#define SOKOBAN_H_  
#include <vector>  

#include "../../../lib/Point2D/Point2D.h"
#include "ASokoban.h"

using namespace std;

class Sokoban : public ASokoban {
public:
	Sokoban(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements);
	void doMovements() override;
private: 
	vector<pair<Point2D, Point2D>> analysePush(Point2D position, Point2D direction);
	void doPush(vector<pair<Point2D, Point2D>>& subMove);
};

#endif