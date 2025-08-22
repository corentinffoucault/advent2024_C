#ifndef NETWORK_H_  
#define NETWORK_H_  

#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

#include "Computer23.h"
#include "Connection.h"

class Network {
public:
    Network();
	void add(string computer);
    unordered_set<string> getLansBy3();
    unordered_set<string> getLansByBronkKerbosch();
    void getLansFromOneConnection(shared_ptr<Connection> connection, shared_ptr<Connection> connectionBis, unordered_set<string>* result, unordered_set<shared_ptr<Connection>, ConnectionKeyHash, ConnectionEqual>* seen);

    ~Network();
private:
    unordered_set<string> bronKerbosch(unordered_set<string> p, unordered_set<string> r);
    unordered_set<shared_ptr<Connection>, ConnectionKeyHash, ConnectionEqual> connections;
	unordered_map<string, shared_ptr<Computer23>> computers;
    regex linkRegex{ "(.+)-(.+)" };
};
#endif /* NETWORK_H_ */