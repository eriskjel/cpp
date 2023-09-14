
#include <iostream>
using namespace std;

int find_sum(const int *table, int length);

int main() {


    int table[20];

    for (int i = 0; i < 20; ++i) {
        table[i] = i + 1;
    }

    int sumFirstTen = find_sum(table, 10);
    int sumNextFive = find_sum(table + 10, 5);
    int sumLastFive = find_sum(table + 15, 5);

    cout << "Sum of first ten elements: " << sumFirstTen << endl;
    cout << "Sum of next five elements: " << sumNextFive << endl;
    cout << "Sum of last five elements: " << sumLastFive << endl;

    return 0;
}

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }


    return sum;
}

