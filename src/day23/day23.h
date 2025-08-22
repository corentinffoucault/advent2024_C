#include <filesystem>
#include <string>
#include <regex>

#include "../ADay/ADay.h"
#include "network/Network.h"

using namespace std;
namespace fs = std::filesystem;

class day23: public ADay {
    public:
        day23(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day23();
    private:
        string convertToResult(unordered_set<string> lan);
        Network createData();
        regex regexContainsT{ "t[A-z]" };
};