#include <filesystem>
#include <regex>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "Robot.h"

using namespace std;
namespace fs = std::filesystem;

class day14Data {
public:
    Robot robot;
};

class day14: public ADay {
    public:
        day14(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day14();
    private:
        vector<Robot> createData(Point2D size);
        Robot extractInfo(string line, Point2D size);
        int printFile();
        vector<string> createMap(Point2D size);
        regex pointFinder{ "p=([0-9]+),([0-9]+) v=(-?[0-9]+),(-?[0-9]+)" };
};