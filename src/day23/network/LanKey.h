#ifndef LANKEY_H  
#define LANKEY_H

#include <unordered_set>
#include <string>

using namespace std;

class LanKey {
public:
	static string generateKey(vector<string> computers);
};
#endif /* LANKEY_H */
