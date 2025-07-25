#include <filesystem>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day16Data {
public:
    Point2D start;
    Point2D end; 
    vector<string> maze;
};

class day16: public ADay {
    public:
        day16(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day16();
    private:
        day16Data createData();
};