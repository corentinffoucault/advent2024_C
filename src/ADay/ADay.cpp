#include "ADay.h"

using namespace std;
namespace fs = std::filesystem;

ADay::ADay(fs::path _currentPath) {
	currentPath = _currentPath;
}
string ADay::run() {
	return "0";
}