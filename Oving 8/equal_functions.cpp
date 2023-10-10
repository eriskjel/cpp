#include <iostream>
#include <iomanip>
#include <cmath>

template <typename Type>
bool equal(Type a, Type b) {
    std::cout << "Using generic version\n";
    return a == b;
}

bool equal(double a, double b) {
    std::cout << "Using specialized version for double\n";
    return std::abs(a - b) < 0.00001;
}

int main() {
    int a = 5, b = 5;
    if (equal(a, b)) {
        std::cout << "Integers are equal\n";
    }

    double x = 3.14159, y = 3.141592;
    std::cout << std::setprecision(10);
    if (equal(x, y)) {
        std::cout << "Doubles are equal\n";
    }

    return 0;
}
