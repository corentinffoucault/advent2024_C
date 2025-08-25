#include <filesystem>
#include <regex>
#include <string>

#include "../ADay/ADay.h"
#include "graph/Graph.h"

using namespace std;
namespace fs = std::filesystem;

class day24: public ADay {
public:
    day24(fs::path _currentPath);
    string run() override;
    string run2() override;
protected:
    ~day24();
private:
    Graph createData();
    regex entryRegex{ "([a-z0-9]{3}): ([01]{1})" };
    regex doorRegex{ "([a-z0-9]{3}) (OR|AND|XOR) ([a-z0-9]{3}) -> ([a-z0-9]{3})" };
};