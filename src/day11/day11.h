#include <filesystem>
#include <string>
#include <vector>
#include <cstdint>
#include <map>

#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day11: public ADay {
    public:
        day11(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day11();
    private:
        int limit = 0;
        map<string, int_least64_t> cache;
        vector<int_least64_t> createData();
        int_least64_t buildNextLevel(int_least64_t currentValue, int indexLoop);
};