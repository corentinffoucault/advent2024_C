#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <limits>
#include <numeric>
#include <set>

#include "PadSolver.h"

PadSolver::PadSolver(Permuter permuter): permuter(permuter) {
}

PadSolver::~PadSolver() {

}

int_least64_t PadSolver::solve(string password, int depth) {
    return getListCommand(password, depth, numPad, Point2D(0, 0));
}

vector<string> PadSolver::cleanSublistCommand(string subListCommand, Point2D invalidPoint, Point2D previousPos) {
    set<string> permutations = permuter.permute(subListCommand);
    set<string> validCommands;

    for (const auto& command : permutations) {
        Point2D currentPosition = previousPos;
        bool isInvalid = false;

        for (char c : command) {
            switch (c) {
            case '<': currentPosition = currentPosition + Point2DDirection::West; break;
            case '>': currentPosition = currentPosition + Point2DDirection::East; break;
            case '^': currentPosition = currentPosition + Point2DDirection::South; break;
            case 'v': currentPosition = currentPosition + Point2DDirection::North; break;
            default:  currentPosition = currentPosition + Point2DDirection::Origin; break;
            }

            if (currentPosition == invalidPoint) {
                isInvalid = true;
                break;
            }
        }

        if (!isInvalid) {
            validCommands.insert(command + "A");
        }
    }

    return vector<string>(validCommands.begin(), validCommands.end());
}

string PadSolver::getListCommandForOneChar(char value, map<char, Point2D> pad, Point2D position) {
    Point2D nextPosition = pad[value];
    Point2D diff = position - nextPosition;
    ostringstream result;
    if (diff.getX() > 0) {
        result << string(diff.getX(), '<');
    } else if (diff.getX() < 0) {
        result << string(-diff.getX(), '>');
    }

    if (diff.getY() > 0) {
        result << string(diff.getY(), 'v');
    } else if (diff.getY() < 0) {
        result << string(-diff.getY(), '^');
    }

    return result.str();
}

int_least64_t PadSolver::getListCommand(string listCommand, int depth, map<char, Point2D> padDir, Point2D invalidPoint) {
	char previousVal = 'A';
	Point2D currentPosition = padDir[previousVal];
	int_least64_t result = 0;
	for (char it : listCommand) {
        pair<char, char> movement = make_pair(previousVal, it);
        pair<pair<char, char>, int> movementByDepth = make_pair(movement, depth);
		if (!seen.contains(movementByDepth)) {
			string possibleMovement = getListCommandForOneChar(it, padDir, currentPosition);
			if (!possibility.contains(movement)) {
				possibility[movement] = cleanSublistCommand(possibleMovement, invalidPoint, padDir[previousVal]);
			}
			seen[movementByDepth] = getMinimalAlternative(possibility[movement], depth);
		}
		currentPosition = padDir[it];
		int_least64_t tmp = seen[movementByDepth];
		previousVal = it;
		result += tmp;
	}
	return result;
}

int_least64_t PadSolver::getMinimalAlternative(vector<string> allValidSubListCommand, int depth) {
	return accumulate(
		allValidSubListCommand.begin(),
		allValidSubListCommand.end(),
		numeric_limits<int_least64_t>::max(),
		[&](int_least64_t minSize, string currentCommand) {
			int_least64_t tmpValue = currentCommand.length();
			if (depth != 0) {
				tmpValue = getListCommand(currentCommand, depth - 1, dirPad, Point2D(0, 1));
			}
			return min(tmpValue, minSize);
		}
	);
}