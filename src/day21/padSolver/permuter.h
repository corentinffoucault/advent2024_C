#ifndef PERMUTER_H_  
#define PERMUTER_H_  

#include <set>
#include <string>

using namespace std;

class Permuter {
public:
	Permuter();
	set<string> permute(string input);
	~Permuter();
private:
	void permuteHelper(string str, string result, set<string>* output);
};
#endif /* PERMUTER_H_ */