#include <filesystem>
#include <string>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day6Data {
public:
    vector<string> matrix;
	Point2D initialCoord = Point2D(0,0);
};

class day6: public ADay {
    public:
        day6(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day6();
    private:
        day6Data createData();
        Point2D rotate(Point2D dir);
        string getDir(Point2D dir);
        bool move(day6Data data); 
        set<Point2D> initialRun(day6Data data);
};