#ifndef ADAY_H_
#define ADAY_H_
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct ADay {
    public:
        ADay(fs::path _currentPath);
        virtual string run() = 0;
    protected:
        ~ADay() {}
        fs::path currentPath;
};
#endif  /* !ADAY_H_ */