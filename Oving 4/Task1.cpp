#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {





    std::vector<int> list = {1, 2, 3, 4, 5};

    cout << "Front: " << list.front() << ", Back: " << list.back() << endl;

    list.emplace(list.begin() + 1, 7);

    cout << "Front after emplace: " << list.front() << endl;

    auto result = find(list.begin(), list.end(), 3);

    if (result != list.end()){
        cout << "Element found: " << *result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }


    return 0;
}
