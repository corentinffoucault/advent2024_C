#ifndef GRAPH_H_  
#define GRAPH_H_  
#include <filesystem>
#include <string>
#include <unordered_map>
#include <utility>

#include "Door.h"
#include "InitialEntry.h"

using namespace std;
namespace fs = std::filesystem;

class Graph {
public:
    Graph(unordered_map<string, Door> informations, unordered_map<string, InitialEntry> initialEntry);
    ~Graph();
    pair<int_least64_t, unordered_map<string, vector<string>>> evalAll();
    void solvePart2();
private:
    string returnListInString(vector<string> items, string separator);
    string returnInformationInString(string separator, string operatorStr, string color, string shape);
    void extractInfo(const string& fileName);
    unordered_map<string, Door> informations;
    unordered_map<string, InitialEntry> initialEntry;
};
#endif /* GRAPH_H_ */