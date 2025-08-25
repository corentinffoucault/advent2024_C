#ifndef DOOR_H_  
#define DOOR_H_  

#include <string>
#include <unordered_map>
#include <vector>

#include "InitialEntry.h"

using namespace std;

class Door {
public:
    Door();
    Door(string v1, string v2, string op, string resultName);
    int eval(unordered_map<string, Door>& informations, unordered_map<string, InitialEntry>& initialEntry);
    vector<string> listInitialEntry(unordered_map<string, Door> informations);
    string toString() const;
    string getResultName() const;
    string getOp() const;
    string getV1() const;
    string getV2() const;
private:
    string v1, v2, op, resultName;
    int res;
};
#endif /* DOOR_H_ */