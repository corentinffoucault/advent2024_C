#include <filesystem>
#include <regex>
#include <set>

#include "../ADay/ADay.h"

using Container = vector<string>;

using namespace std;
namespace fs = std::filesystem;

class multiplyReaderState {
public:
    bool multipliesEnable = true;
    int currentValue = 0;
};

class day3: public ADay {
    public:
        day3(fs::path _currentPath);
        string run() override;
        string run2() override;
    protected:
        ~day3();
    private:
		void analyzeLine(string line, multiplyReaderState *currentState) const;
        regex mulFinder{ "mul\\(([0-9]{0,3}),([0-9]{0,3})\\)|do\\(\\)|don't\\(\\)" };
};