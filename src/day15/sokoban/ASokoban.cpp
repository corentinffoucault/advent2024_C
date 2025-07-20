#include <deque>
#include <string>
#include <vector>

#include "../../../lib/Point2D/Point2D.h"
#include "ASokoban.h"
#include <iostream>

ASokoban::ASokoban(Point2D _initialPoint, vector<string> _fullMap, vector<Point2D> _movements) {
    initialPoint = _initialPoint;
    fullMap = _fullMap;
    movements = _movements;
}

void ASokoban::doMovements() {
    cout << "do movements" << endl << flush;
}

int_least64_t ASokoban::getGpsSum() {
    int_least64_t res = 0;
	int y = 0;
    for (string line : fullMap) {
		int x = 0;
        for (char item : line) {
            if (item == 'O' || item == '[') {
				res += gps(x, y);
            }
			x++;
        }
		y++;
    }
    return res;
}

int_least64_t ASokoban::gps(int x, int y) {
	return (100 * static_cast<int_least64_t>(y)) + static_cast<int_least64_t>(x);
}