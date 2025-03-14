#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace PathUtils {
	fs::path getResourcesPath(int dayIndex) {
		return fs::current_path().append("..").append("resources").append(std::format("day{}.txt", dayIndex));
	}
}