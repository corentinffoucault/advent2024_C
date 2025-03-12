#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class ADay {
    public:
        ADay(fs::path _currentPath) {
            currentPath = _currentPath;
        }
        ~ADay() {}
        virtual string run() = 0;
    protected:
        fs::path currentPath;
};