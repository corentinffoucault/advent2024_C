#include "KeyOrLock.h"

KeyOrLock::KeyOrLock(array<int, 5> v) : value(v) {
}

KeyOrLock KeyOrLock::fromStrings(array<string, 7> spaceSeparated) {
    array<int, 5> info{ 0,0,0,0,0 };
    for (const auto& line : spaceSeparated) {
        for (size_t i = 0; i < 5; ++i) {
            if (line[i] == '#') {
                info[i] += 1;
            }
        }
    }
    return KeyOrLock(info);
}

array<int, 5> KeyOrLock::add(KeyOrLock other) {
    array<int, 5> result{};
    for (size_t i = 0; i < 5; ++i) {
        result[i] = value[i] + other.value[i];
    }
    return result;
}

bool KeyOrLock::areComplement(KeyOrLock other) {
    array<int, 5> fusion = this->add(other);
    for (int v : fusion) {
        if (v > 7) return false;
    }
    return true;
}