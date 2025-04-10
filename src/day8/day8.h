#include <filesystem>
#include <string>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include <map>
#include <set>

using namespace std;
namespace fs = std::filesystem;

class day8Data {
public:
    vector<string> matrix;
    int x_size = 0;
	int y_size = 0;
};

class day8: public ADay {
    public:
        day8(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day8();
    private:
        day8Data createData();
        int countAntiNodes1(map<char, vector<Point2D>> groupedAntenna, day8Data data);
        int countAntiNodes2(map<char, vector<Point2D>> groupedAntenna, day8Data data);
        bool isOnGrid(Point2D point, day8Data data);
        set<Point2D> antiNodesForPart1(Point2D a, Point2D b, Point2D diff, day8Data data);
        set<Point2D> antiNodesForPart2(Point2D a, Point2D diff, day8Data data);
        map<char, vector<Point2D>> parseGrid(day8Data data);
        bool isNotAntenna(Point2D point, day8Data data);
};