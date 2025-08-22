#include <vector>

#include "LanKey.h"
#include "Network.h"

Network::Network() {
}

Network::~Network() {
}

void Network::add(string linkedComputer) {
    smatch computersFromLink;
    regex_match(linkedComputer, computersFromLink, linkRegex);

    string from = computersFromLink[1];
    string to = computersFromLink[2];

    auto [c1, inserted1] = computers.try_emplace(from, make_shared<Computer23>(from));
    auto [c2, inserted2] = computers.try_emplace(to, make_shared<Computer23>(to));

    c1->second->addComputer(to);
    c2->second->addComputer(from);
	Connection connection(c1->second, c2->second);
    connections.insert(make_shared<Connection>(connection));
}


unordered_set<string> Network::getLansBy3() {
    unordered_set<string> result;
    unordered_set<shared_ptr<Connection>, ConnectionKeyHash, ConnectionEqual> seen;
    for (auto firstConnection = connections.begin(); firstConnection != connections.end(); ++firstConnection) {
		seen.insert(*firstConnection);
        for (auto secondConnection = next(firstConnection); secondConnection != connections.end(); ++secondConnection) {
            getLansFromOneConnection(*firstConnection, *secondConnection, &result, &seen);
        }
    }
	return result;
}

void Network::getLansFromOneConnection(shared_ptr<Connection> firstConnection, shared_ptr<Connection> secondConnection, unordered_set<string>* lans, unordered_set<shared_ptr<Connection>, ConnectionKeyHash, ConnectionEqual>* seen) {
    shared_ptr<Computer23> c1a = firstConnection->getFirstComputer();
    shared_ptr<Computer23> c1b = firstConnection->getSecondComputer();
    shared_ptr<Computer23> c2a = secondConnection->getFirstComputer();
    shared_ptr<Computer23> c2b = secondConnection->getSecondComputer();

    shared_ptr<Computer23> commonComputer = nullptr;
    shared_ptr<Connection> connectionToFind;

    if (c1a == c2a) {
        connectionToFind = make_shared<Connection>(c1b, c2b);
        commonComputer = c2b;
    } else if (c1a == c2b) {
        connectionToFind = make_shared<Connection>(c1b, c2a);
        commonComputer = c2a;
    } else if (c1b == c2a) {
        connectionToFind = make_shared<Connection>(c1a, c2b);
        commonComputer = c2b;
    } else if (c1b == c2b) {
        connectionToFind = make_shared<Connection>(c1a, c2a);
        commonComputer = c2a;
    }
    if (commonComputer != nullptr && !seen->contains(connectionToFind)) {
        if (connections.contains(connectionToFind)) {
            lans->insert(LanKey::generateKey(vector({ c1a->getName(), c1b->getName(), commonComputer->getName() })));
        }
    }
}

unordered_set<string> Network::getLansByBronkKerbosch() {
    unordered_set<string> allComputers;
    for (auto &[key, _] : computers) {
        allComputers.insert(key);
    }
    unordered_set<string> r;
    return bronKerbosch(allComputers, r);
}

unordered_set<string> Network::bronKerbosch(unordered_set<string> p, unordered_set<string> r) {
    if (p.empty()) {
        return r;
    }
    auto& withMostNeighbors = *std::max_element(
        p.begin(), p.end(),
        [&](const string& a, const string& b) {
            return computers[a]->size() < computers[b]->size();
        }
    );

    unordered_set<string> bestLAN;
    unordered_set<shared_ptr<Computer23>> newP;
    shared_ptr<Computer23> withMostNeighborsPtr = computers[withMostNeighbors];

    for (auto &currentComputer : p) {
        if (withMostNeighborsPtr->values().contains(currentComputer)) {
            continue;
        }
        unordered_set<string> newR = r;
        newR.insert(currentComputer);

        shared_ptr<Computer23> currentComputerPtr = computers[currentComputer];
        unordered_set<string> candidate = bronKerbosch(currentComputerPtr->intersectValue(p), newR);

        if (candidate.size() > bestLAN.size()) {
            bestLAN = candidate;
        }
    }

    return bestLAN;
}