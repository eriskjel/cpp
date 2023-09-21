
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

void testInitialize() {
    Set set;
    set.initialize(1, 10);
    std::cout << "Testing initialize:" << std::endl;
    set.printList();
    std::cout << std::endl;
}

void testAddInt() {
    Set set;
    set.initialize(1, 10);
    std::cout << "Before adding 9:" << std::endl;
    set.printList();

    set.addInt(9);
    std::cout << "After trying to add 9:" << std::endl;
    set.printList();

    set.addInt(11);
    std::cout << "After adding 11:" << std::endl;
    set.printList();
    std::cout << std::endl;
}

void testUnion() {
    Set set1, set2;
    set1.initialize(1, 10);
    set2.initialize(5, 15);

    std::cout << "Set 1:" << std::endl;
    set1.printList();
    std::cout << "Set 2:" << std::endl;
    set2.printList();

    Set set3 = set1.findUnion(set2);
    std::cout << "Union of Set 1 and Set 2:" << std::endl;
    set3.printList();
    std::cout << std::endl;
}

void testAssignmentOperator() {
    Set set1, set2;
    set1.initialize(1, 5);

    std::cout << "Set 1 before assignment:" << std::endl;
    set1.printList();

    set2 = set1;

    std::cout << "Set 2 after assignment:" << std::endl;
    set2.printList();
    std::cout << std::endl;
}



int main() {
    testInitialize();
    testAddInt();
    testUnion();
    testAssignmentOperator();

    return 0;
}
