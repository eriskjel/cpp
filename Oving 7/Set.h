//
// Created by eriks on 21/09/2023.
//

#ifndef OVING_7_SET_H
#define OVING_7_SET_H


#include <vector>

class Set{


public:
    std::vector<int> set;

    //constructor
    Set();

    //constructor which takes a vector
    Set(std::vector<int> set);

    void initialize(int start, int stop);



    Set findUnion(const Set& otherSet) const;
    bool addInt(int number);
    Set& operator=(const Set& otherSet);
    void printList();


};

#endif //OVING_7_SET_H
