#include <iostream>
using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    // Initial values and addresses
    cout << "Initial state:" << endl;
    cout << "Variabel i har verdi " << i << " og adresse " << &i << endl;
    cout << "Variabel j har verdi " << j << " og adresse " << &j << endl;
    cout << "Pekeren p har verdi " << p << " og adresse " << &p << " og peker på verdien " << *p << endl;
    cout << "Pekeren q har verdi " << q << " og adresse " << &q << " og peker på verdien " << *q << endl;
    cout << endl;  // Empty line for separation

    // Updating the values as per the given steps
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;

    // Updated values and addresses after modifications
    cout << "After modifications:" << endl;
    cout << "Variabel i har verdi " << i << " og adresse " << &i << endl;
    cout << "Variabel j har verdi " << j << " og adresse " << &j << endl;
    cout << "Pekeren p har verdi " << p << " og adresse " << &p << " og peker på verdien " << *p << endl;
    cout << "Pekeren q har verdi " << q << " og adresse " << &q << " og peker på verdien " << *q << endl;
    cout << endl;  // Empty line for separation

    cout << "Final output: " << *p << " " << *q << endl;

    return 0;
}
