#include <filesystem>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "Topographic.h"

using namespace std;
namespace fs = std::filesystem;

class day10Data {
public:
    Topographic topo;
};

class day10: public ADay {
    public:
        day10(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day10();
    private:
        Topographic createData();
};