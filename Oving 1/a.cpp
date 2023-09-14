#include <iostream>
#include <fstream>


using namespace std;

void taskA();


int main() {
    taskA();
    return 0;
}


void taskA(){
    const int length = 5;

    int under10 = 0;
    int mellom10og20 = 0;
    int over20 = 0;
    double temp;

    cout << "Du skal skrive inn 5 temperaturer: " << endl;

    for (int i = 1; i <= length; ++i) {
        cout << "Temperatur nr " << i << ": ";
        cin >> temp;

        if (temp < 10) {
            under10++;
        } else if (temp >= 10 && temp <= 20) {
            mellom10og20++;
        } else if (temp > 20) {
            over20++;
        }
        else{
            cout << "Ugyldig temperatur" << endl;
        }
    }

    cout << "Antall under 10 grader: " << under10 << endl;
    cout << "Antall mellom 10 og 20 grader: " << mellom10og20 << endl;
    cout << "Antall over 20 grader: " << over20 << endl;
}


