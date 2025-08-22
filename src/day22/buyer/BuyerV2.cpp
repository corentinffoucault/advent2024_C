#include "BuyerV2.h"

BuyerV2::BuyerV2(Secret secret): Buyer(secret) {
}

BuyerV2::~BuyerV2() {

}

void BuyerV2::solve(int depth, unordered_map<int, int>* sequenceToValues) {
    alreadySeen.reserve(depth);

    int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = secret.getUnitValue();

    for (int i = 1; i <= 4; ++i) {
        secret.incrementSecret();
        x1 = x2;
        x2 = x3;
        x3 = x4;
        x4 = secret.getUnitValue();
    }
    for (int i = 5; i <= depth; ++i) {
        secret.incrementSecret();
        x0 = x1;
        x1 = x2;
        x2 = x3;
        x3 = x4;
        x4 = secret.getUnitValue();
        int currentSequence = keySequence(x0, x1, x2, x3, x4);
        auto [it, inserted] = alreadySeen.insert(currentSequence);
        if (inserted) {
            auto [it, inserted] = sequenceToValues->try_emplace(currentSequence, 0);
            it->second += x4;
        }
    }
}

int BuyerV2::keySequence(int x0, int x1, int x2, int x3, int x4) {
    auto norm = [](int d) { return d + 9; };
    return ((norm(x1-x0) * 19 + norm(x2 - x1)) * 19 + norm(x3 - x2)) * 19 + norm(x4 - x3);
}