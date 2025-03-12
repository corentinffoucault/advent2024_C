#include <filesystem>
#include "../ADay.cpp"

using namespace std;
namespace fs = std::filesystem;

class day1: public ADay {
    public:
        day1(fs::path _currentPath);
        ~day1();
        int run();
};
