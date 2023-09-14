#include <iostream>
#include <fstream>


using namespace std;

void read_temperatures(double temperatures[], int length);
void count_temperatures(const double temperatures[], int length, int &under10, int &mellom10og20, int &over20);

int main() {

    double temperatures[5];
    int length = 5;
    read_temperatures(temperatures, length);

    return 0;
}




void read_temperatures(double temperatures[], int length) {

    const char filename[] = "../temperatures.dat";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Kunne ikke åpne filen " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length && file >> temperatures[i]; ++i) {
        cout << "Temperature " << i + 1 << ": " << temperatures[i] << endl;
    }

    file.close();

    int under10 = 0;
    int mellom10og20 = 0;
    int over20 = 0;

    count_temperatures(temperatures, length, under10, mellom10og20, over20);

    cout << "Antall under 10 grader: " << under10 << endl;
    cout << "Antall mellom 10 og 20 grader: " << mellom10og20 << endl;
    cout << "Antall over 20 grader: " << over20 << endl;
}

void count_temperatures(const double temperatures[], int length, int &under10, int &mellom10og20, int &over20) {
    for (int i = 0; i < length; ++i) {
        if (temperatures[i] < 10) {
            under10++;
        } else if (temperatures[i] >= 10 && temperatures[i] <= 20) {
            mellom10og20++;
        } else if (temperatures[i] > 20) {
            over20++;
        }
    }
}

