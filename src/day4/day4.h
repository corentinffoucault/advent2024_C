#include <filesystem>
#include <regex>
#include <set>

#include "../ADay/ADay.h"

using namespace std;
namespace fs = std::filesystem;

class day4: public ADay {
    public:
        day4(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day4();
    private:
		string createLine(string line);
        bool charIsX(char character);
        bool charIsA(char character);
        bool findWord(vector<string> matrix, size_t indexLine, size_t indexCol, int incrLine, int incrCol);
        bool findMasLimit(vector<string> matrix, size_t indexLine, size_t indexCol);
        int findWordLimit(vector<string> matrix, size_t indexLine, size_t indexCol);
        bool findDiagMS_top_bottom(vector<string> matrix, size_t indexLine, size_t indexCol);
        bool findDiagMS_bottom_top(vector<string> matrix, size_t indexLine, size_t indexCol);
        int findXMas(vector<string> matrix);
        int findCrossMas(vector<string> matrix);
};