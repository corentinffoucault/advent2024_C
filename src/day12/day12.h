#include <filesystem>
#include <string>
#include <map>
#include <set>

#include "../../lib/Point2D/Point2D.h"
#include "../ADay/ADay.h"
#include "garden/Garden.h"

using namespace std;
namespace fs = std::filesystem;

class day12: public ADay {
   public:
       day12(fs::path _currentPath);
       string run() override;
       string run2() override;
   protected:
       ~day12();
   private:
       map<char, set<Point2D>> createData();
};