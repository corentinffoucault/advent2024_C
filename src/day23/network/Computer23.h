# ifndef COMPUTER23_H_  
# define COMPUTER23_H_  

#include <memory>
# include <string>
# include <unordered_set>

using namespace std;

class Computer23 {
public:
    Computer23(string name);
    void addComputer(string computer);
    unordered_set<string> intersectValue(unordered_set<string> entry);
    unordered_set<string> values();
    bool operator==(const Computer23& other) const;
    bool operator<(const Computer23& other) const;
    string getName() const;
    int size();
    string toString();
    ~Computer23();
private:
    unordered_set<string> connectedComputer;
    string name;

};
#endif /* COMPUTER23_H_ */
