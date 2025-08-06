#include <filesystem>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day20Data {
public:
    Point2D start;
    Point2D end; 
    vector<string> maze;
};

class day20: public ADay {
    public:
        day20(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day20();
    private:
        day20Data createData();
};