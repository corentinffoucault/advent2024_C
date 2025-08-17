#ifndef PAD_SOLVER_H_  
#define PAD_SOLVER_H_  

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "../../../lib/Point2D/Point2D.h"
#include "Permuter.h"

class PadSolver {
public:
	PadSolver(Permuter permuter);
	int_least64_t solve(string password, int depth);
    ~PadSolver();
private:
	int_least64_t getListCommand(string listCommand, int depth, map<char, Point2D> pad, Point2D invalidPoint);
	string getListCommandForOneChar(char value, map<char, Point2D> pad, Point2D position);
	int_least64_t getMinimalAlternative(vector<string> allValidSubListCommand, int depth);
	vector<string> cleanSublistCommand(string subListCommand, Point2D invalidPoint, Point2D previousPos);
	Permuter permuter;
	map<pair<char, char>, vector<string>> possibility;
	map<pair<pair<char, char>, int>, int_least64_t> seen;
	map<char, Point2D> numPad = {
		{'0', Point2D(1, 0)},
		{'A', Point2D(2, 0)},
		{'1', Point2D(0, 1)},
		{'2', Point2D(1, 1)},
		{'3', Point2D(2, 1)},
		{'4', Point2D(0, 2)},
		{'5', Point2D(1, 2)},
		{'6', Point2D(2, 2)},
		{'7', Point2D(0, 3)},
		{'8', Point2D(1, 3)},
		{'9', Point2D(2, 3)}
	};

	map<char, Point2D> dirPad = {
		{'<', Point2D(0, 0)},
		{'v', Point2D(1, 0)},
		{'>', Point2D(2, 0)},
		{'^', Point2D(1, 1)},
		{'A', Point2D(2, 1)}
	};
};
#endif /* PAD_SOLVER_H_ */