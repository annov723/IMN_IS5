#include <iostream>

#include "matrix.h"
#include "zad1.h"

using namespace std;

int main()
{
    //z.1
    Zad1 zad11;
    vector<double> wyniki11u = zad11.metodaPicarda();
    vector<double> wyniki11z = zad11.getZ( wyniki11u);

    Zad1 zad12;
    vector<double> wyniki12u = zad12.metodaNewtona();
    vector<double> wyniki12z = zad11.getZ( wyniki12u);

    //z.2
    vector<double> wyniki2u = zad11.niejawnaMetodaRK2();
    vector<double> wyniki2z = zad11.getZ( wyniki2u);

    ofstream outP1("../data/wyniki1.txt");
    if (!outP1.is_open())
    {
        cerr << "Blad podczas otwierania pliku." << endl;
        return 1;
    }

    Matrix::write_to_file(&outP1, wyniki11u);
    Matrix::write_to_file(&outP1, wyniki11z);
    Matrix::write_to_file(&outP1, wyniki12u);
    Matrix::write_to_file(&outP1, wyniki12z);
    Matrix::write_to_file(&outP1, wyniki2u);
    Matrix::write_to_file(&outP1, wyniki2z);

    outP1.close();

    //generowanie wykresow
    int result = system("python3 ../wykresy.py"); // Use python or python3 depending on your setup
    if (result != 0)
    {
        std::cerr << "Blad podczas generowania wykresu." << std::endl;
    }

    return 0;
}