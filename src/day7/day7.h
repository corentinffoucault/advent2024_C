#include <filesystem>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "Equation.h"

using namespace std;
namespace fs = std::filesystem;

class day7Data {
public:
    vector<Equation> equations;
};

class day7: public ADay {
    public:
        day7(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day7();
    private:
        day7Data createData();
};