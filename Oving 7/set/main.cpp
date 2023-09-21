#include "Set.h"
#include <random>
#include <iostream>

//initialize methods
void testInitialize();
void testAddInt();
void testUnion();
void testAssignmentOperator();

int main() {
    testInitialize();
    testAddInt();
    testUnion();
    testAssignmentOperator();

    return 0;
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




