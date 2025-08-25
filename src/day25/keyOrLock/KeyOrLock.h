#ifndef KEY_OR_LOCK_H_  
#define KEY_OR_LOCK_H_  

#include <string>
#include <array>

using namespace std;

class KeyOrLock {
public:
    KeyOrLock(array<int, 5> v);
    static KeyOrLock fromStrings(array<string, 7> spaceSeparated);
    array<int, 5> add(KeyOrLock other);
    bool areComplement(KeyOrLock other);
private:
    array<int, 5> value{};
};
#endif /* KEY_OR_LOCK_H_ */