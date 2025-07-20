#include <filesystem>
#include <map>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day15Data {
public:
    Point2D initialPoint;
    vector<string> fullMap;
    vector<Point2D> movements;
};

class day15: public ADay {
    public:
        day15(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day15();
    private:
        day15Data createData();
        Point2D getDir(char dirChar);
		map<char, Point2D> directions = {
			{'^', Point2D(0, -1)},
			{'<', Point2D(-1, 0)},
			{'>', Point2D(1, 0)},
			{'v', Point2D(0, 1)}
		};
};