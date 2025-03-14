#include <filesystem>
#include <set>

#include "../ADay/ADay.h"

using Container = vector<string>;

using namespace std;
namespace fs = std::filesystem;

class day2: public ADay {
    public:
        day2(fs::path _currentPath);
        string run() override;
    protected:
        ~day2();
    private:
		bool isSafe(string my_text); 
        set<string> toSet(Container splittedLine);
        vector<int> isSafeList(Container splittedLine, int dropIndex);
        template <typename T>
        vector<T> copyWithoutIndex(const std::vector<T>& input, size_t index);
};
