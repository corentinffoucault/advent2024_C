#include <filesystem>
#include <string>
#include <vector>
#include <regex>

#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day21: public ADay {
    public:
        day21(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day21();
    private:
        vector<string> createData();
        regex nonDigit{ "[^0-9]" };
};