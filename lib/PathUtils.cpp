#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

namespace PathUtils {
	fs::path getResourcesPath(int dayIndex) {
		fs::path currentPathStr = fs::current_path();
		if (currentPathStr.string().ends_with("build")) {
			return fs::current_path().append("..").append("resources").append(format("day{}.txt", dayIndex));
		}
		return fs::current_path().append("resources").append(format("day{}.txt", dayIndex));
	}
}