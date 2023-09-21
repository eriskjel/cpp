#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

// Member function
Fraction Fraction::operator-(int value) const {
    Fraction result(numerator - value * denominator, denominator);
    result.reduce();
    return result;
}

// Non-member function
Fraction operator-(int value, const Fraction &fraction) {
    Fraction result(value * fraction.denominator - fraction.numerator, fraction.denominator);
    result.reduce();
    return result;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    // Testing new operators
    Fraction result1 = a - 5; // Using the member function version
    Fraction result2 = 5 - a; // Using the non-member function version

    print("a - 5 = ", result1);
    print("5 - a = ", result2);
}

/**
5 - 3: Bruker den innebygde operatøren for heltall. Resultat: 2.

2 - fraction1: Bruker den ikke-medlems overlastede - fordi venstre operand er et heltall og høyre operand er en Fraction.

(Resultat fra 2) - 7: Bruker medlemsfunksjonen - fordi venstre operand er en Fraction og høyre operand er et heltall.

(Resultat fra 3) - fraction2: Bruker medlemsfunksjonen - hvis den er definert for Fraction - Fraction.
*/