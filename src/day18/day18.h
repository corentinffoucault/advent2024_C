#include <filesystem>
#include <regex>
#include <string>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include <vector>

using namespace std;
namespace fs = std::filesystem;

class day18: public ADay {
    public:
        day18(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day18();
    private:
        vector<Point2D>  createData();
        regex pointFinder{ "(\\d+),(\\d+)" };
};