#include <filesystem>
#include <regex>
#include <string>
#include <vector>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "Machine.h"

using namespace std;
namespace fs = std::filesystem;

class day13Data {
public:
    Machine topo;
};

class day13: public ADay {
    public:
        day13(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day13();
    private:
        regex buttonA{ "Button A: X\\+([0-9]+), Y\\+([0-9]+)" };
        regex buttonB{ "Button B: X\\+([0-9]+), Y\\+([0-9]+)" };
        regex prize{ "Prize: X=([0-9]+), Y=([0-9]+)" };
        vector<Machine> createData();
        Point2D extractInfo(string line, regex button);
};