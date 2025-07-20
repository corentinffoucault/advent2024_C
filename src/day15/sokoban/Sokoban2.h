#ifndef SOKOBAN2_H_  
#define SOKOBAN2_H_  
#include <map>
#include <string>
#include <vector>  
#include <utility>

#include "../../../lib/Point2D/Point2D.h"
#include "ASokoban.h"

using namespace std;

class Sokoban2 : public ASokoban {
public:
	Sokoban2(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements);
	void doMovements()  override;
	void extends();
private: 
	string extendsChar(char item);
	vector<pair<Point2D, Point2D>> analysePush(Point2D position, Point2D direction);
	map<char, string> convertionMap = {
		{'#', "##"},
		{'O', "[]"},
		{'.', ".."},
		{'@', "@."}
	};
};

#endif