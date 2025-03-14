#include <filesystem>
#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day1: public ADay {
    public:
        day1(fs::path _currentPath);
        string run() override;
    protected:
        ~day1();
};
