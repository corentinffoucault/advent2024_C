#include <filesystem>
#include <string>
#include <vector>

#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day9Data {
public:
    vector<vector<string>> memory;
};

class day9: public ADay {
    public:
        day9(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day9();
    private:
        day9Data createData();
        day9Data rearange(day9Data data);
        day9Data rearange2(day9Data data);
        int_least64_t calculate(day9Data data);
};