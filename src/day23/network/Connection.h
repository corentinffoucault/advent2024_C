#ifndef CONNECTION_H_  
#define CONNECTION_H_

#include "Computer23.h"
#include <memory>

using namespace std;

class Connection {
public:
	Connection(shared_ptr<Computer23> c1, shared_ptr<Computer23> c2);
	string toString();
	string getConnection() const;
	shared_ptr<Computer23> getFirstComputer() const;
	shared_ptr<Computer23> getSecondComputer() const;
	bool operator==(const Connection& other) const;
	~Connection();
private:
	string connection;
	shared_ptr<Computer23> c1;
	shared_ptr<Computer23> c2;
};

struct ConnectionKeyHash {
	size_t operator()(const shared_ptr<Connection>& k) const noexcept {
		const std::string& key = k->getConnection(); // stocke la référence à la string persistante
		return std::hash<std::string>{}(key);
	}
};
struct ConnectionEqual {
	bool operator()(const std::shared_ptr<Connection>& lhs,
		const std::shared_ptr<Connection>& rhs) const noexcept {
		return lhs->getConnection() == rhs->getConnection();
	}
};
#endif /* CONNECTION_H_ */
