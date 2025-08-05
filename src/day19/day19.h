#include <filesystem>
#include <regex>
#include <string>
#include <vector>

#include "../ADay/ADay.h"
#include "towel/TowelPart.h"

using namespace std;
namespace fs = std::filesystem;

class day19Data {
public:
    TowelPart towelPart;
	vector<string> towels;
};

class day19: public ADay {
    public:
        day19(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day19();
    private:
        day19Data createData();
};