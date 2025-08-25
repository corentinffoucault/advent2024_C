#include "InitialEntry.h"

InitialEntry::InitialEntry(int r) : result(r) {
}
int InitialEntry::eval() const {
    return result;
}