#include <filesystem>
#include <string>
#include <regex>

#include "../ADay/ADay.h"
#include "computer/Computer.h"

using namespace std;
namespace fs = std::filesystem;

class day17: public ADay {
    public:
        day17(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day17();
    private:
        Computer createData();
        regex registerRegex{ "Register [ABC]: ([0-9]+)" };
        regex instructionRegex{ "Program: ([0-9,]+)" };
        int_least64_t extractInfo(string line, regex button);
};