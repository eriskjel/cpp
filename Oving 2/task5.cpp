
#include <iostream>
using namespace std;

int main() {


    double number;

    //definer en peker som skal peke til number
    double *numberPtr = &number;

    //definer en referanse som skal refere til number
    double &numberRef = number;

    //tre måter å tilordne verdi til number på
    number = 5.5;
    *numberPtr = 5.5;
    numberRef = 5.5;
    return 0;
}

