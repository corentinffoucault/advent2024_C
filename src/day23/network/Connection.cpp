#include "Connection.h"

Connection::Connection(shared_ptr<Computer23> c1, shared_ptr<Computer23> c2): c1(c1), c2(c2) {
	connection.reserve(5);
	if (*c1 < *c2) {
		connection.append(c1->getName());
		connection.append("-");
		connection.append(c2->getName());
	} else {
		connection.append(c2->getName());
		connection.append("-");
		connection.append(c1->getName());
	}
}

string Connection::toString() {
	return connection;
}

string Connection::getConnection() const {
	return connection;
}

bool Connection::operator==(const Connection& other) const {
	return this->connection == other.connection;
}

shared_ptr<Computer23> Connection::getFirstComputer() const {
	return c1;
}

shared_ptr<Computer23> Connection::getSecondComputer() const {
	return c2;
}

Connection::~Connection() {

}