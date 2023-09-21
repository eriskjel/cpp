
#include "Set.h"
#include <random>
#include <iostream>
#include <algorithm>


void Set::initialize(int start, int stop) {
    for (int i = start; i <= stop; ++i) {
        set.push_back(i);
    }

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(set), std::end(set), rng);
}

Set::Set() {}

Set::Set(std::vector<int> set) : set(set) {}

Set Set::findUnion(const Set& otherSet) const {
    std::vector<int> newVec = set;  // Start with all elements of this set
    for (int num : otherSet.set) {
        if (std::find(newVec.begin(), newVec.end(), num) == newVec.end()) {
            newVec.push_back(num);  // add if not already present
        }
    }
    return Set(newVec);
}


void loopList() {

}

bool Set::addInt(int number) {
    if (std::find(set.begin(), set.end(), number) != set.end())
        return false;
    else
        set.push_back(number);
    return true;
}


Set& Set::operator=(const Set& otherSet) {
    if (this == &otherSet) {
        return *this; // handle self-assignment
    }
    set = otherSet.set;
    return *this;
}

void Set::printList() {
    for (int i = 0; i < set.size(); ++i) {
        std::cout << set[i] << std::endl;
    }
}

