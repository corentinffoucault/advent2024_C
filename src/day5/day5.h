#include <filesystem>
#include <set>

#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day5Data {
public:
    set<string> orders;
    vector<string> linesToAnalyses;
};

class day5: public ADay {
    public:
        day5(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day5();
    private:
        day5Data createData();
        int* analyseAllLine(day5Data data);
        int validNumber(day5Data data, string line);
        vector<string> reorder(day5Data data, vector<string> splittedLine);
        bool checkIsFirst(day5Data data, string item, vector<string> splittedLine);
};