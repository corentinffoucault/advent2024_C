#include <filesystem>
#include <vector>
#include <string>

#include "../ADay/ADay.h"
#include "KeyOrLock/KeyOrLock.h"

using namespace std;
namespace fs = std::filesystem;

class day25Data {
public:
    vector<KeyOrLock> keys;
    vector<KeyOrLock> locks;
};

class day25: public ADay {
public:
    day25(fs::path _currentPath);
    string run() override;
    string run2() override;
protected:
    ~day25();
private:
    day25Data createData();
};