#include <filesystem>
#include <string>
#include <vector>
#include <regex>

#include "../ADay/ADay.h"
#include "buyer/Secret.h"

using namespace std;
namespace fs = std::filesystem;

class day22: public ADay {
    public:
        day22(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day22();
    private:
        vector<Secret> createData();
};