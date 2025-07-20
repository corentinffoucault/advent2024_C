#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <stdexcept>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "day15.h"
#include "sokoban/Sokoban.h"
#include "sokoban/Sokoban2.h"
#include "sokoban/ASokoban.h"

using namespace std;
namespace fs = filesystem;
using Container = vector<string>;

day15::day15(fs::path _currentPath) : ADay(_currentPath) {

}

day15::~day15() {
}

string day15::run() {
    day15Data data = createData();
    Sokoban sokoban = Sokoban(data.initialPoint, data.fullMap, data.movements);
    sokoban.doMovements();
    return to_string(sokoban.getGpsSum());
}

string day15::run2() {
    day15Data data = createData();
    Sokoban2 sokoban = Sokoban2(data.initialPoint, data.fullMap, data.movements);
    sokoban.doMovements();
    return to_string(sokoban.getGpsSum());
}

day15Data day15::createData() {
    day15Data data;
    ifstream file_content(currentPath);
    string line;
    size_t nbLine = 0;
    while (getline(file_content, line)) {
        if (line.empty()) {
            break;
        }
        size_t initialX = line.find('@');
        if (initialX != -1) {
            data.initialPoint = Point2D(initialX, nbLine);
        }
        data.fullMap.push_back(line);
        nbLine++;
    }

    while (getline(file_content, line)) {
        for (char item : line) {
            data.movements.push_back(getDir(item));
        }
    }
    return data;
}

Point2D day15::getDir(char dirChar) {  
   auto it = directions.find(dirChar);  
   if (it != directions.end()) {  
       return it->second;  
   }  
   throw invalid_argument("Invalid direction character");  
}