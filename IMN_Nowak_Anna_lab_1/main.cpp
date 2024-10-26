#include <iostream>

#include "matrix.h"
#include "zad1.h"
#include "zad2.h"

using namespace std;

int main()
{
    //z.1
    double t[2] = {0., 5.};
    Zad1 e1(1., -1., t, 0.01);
    vector<double> e1Wyniki = e1.MetodaJawnaEulera();
    Zad1 e2(1., -1., t, 0.1);
    vector<double> e2Wyniki = e2.MetodaJawnaEulera();
    Zad1 e3(1., -1., t, 1.);
    vector<double> e3Wyniki = e3.MetodaJawnaEulera();

    ofstream outP1("../data/wyniki1.txt");
    if (!outP1.is_open())
    {
        cerr << "Blad podczas otwierania pliku." << endl;
        return 1;
    }

    Matrix::write_to_file(&outP1, e1Wyniki);
    Matrix::write_to_file(&outP1, e2Wyniki);
    Matrix::write_to_file(&outP1, e3Wyniki);

    outP1.close();

    //z.2
    vector<double> rk2Wyniki1 = e1.MetodaRK2();
    vector<double> rk2Wyniki2 = e2.MetodaRK2();
    vector<double> rk2Wyniki3 = e3.MetodaRK2();

    ofstream outP2("../data/wyniki2.txt");
    if (!outP2.is_open())
    {
        cerr << "Blad podczas otwierania pliku." << endl;
        return 1;
    }

    Matrix::write_to_file(&outP2, rk2Wyniki1);
    Matrix::write_to_file(&outP2, rk2Wyniki2);
    Matrix::write_to_file(&outP2, rk2Wyniki3);

    outP2.close();

    //z.3
    vector<double> rk4Wyniki1 = e1.MetodaRK4();
    vector<double> rk4Wyniki2 = e2.MetodaRK4();
    vector<double> rk4Wyniki3 = e3.MetodaRK4();

    ofstream outP3("../data/wyniki3.txt");
    if (!outP3.is_open())
    {
        cerr << "Blad podczas otwierania pliku." << endl;
        return 1;
    }

    Matrix::write_to_file(&outP3, rk4Wyniki1);
    Matrix::write_to_file(&outP3, rk4Wyniki2);
    Matrix::write_to_file(&outP3, rk4Wyniki3);

    outP3.close();

    //z.4
    Zad2 k1(0.5);
    Zad2 k2(0.8);
    Zad2 k3(1.0);
    Zad2 k4(1.2);

    ofstream outP4("../data/wyniki4.txt");
    if (!outP4.is_open())
    {
        cerr << "Blad podczas otwierania pliku." << endl;
        return 1;
    }

    Matrix::write_to_file(&outP4, k1.getWynikiI());
    Matrix::write_to_file(&outP4, k1.getWynikiQ());
    Matrix::write_to_file(&outP4, k2.getWynikiI());
    Matrix::write_to_file(&outP4, k2.getWynikiQ());
    Matrix::write_to_file(&outP4, k3.getWynikiI());
    Matrix::write_to_file(&outP4, k3.getWynikiQ());
    Matrix::write_to_file(&outP4, k4.getWynikiI());
    Matrix::write_to_file(&outP4, k4.getWynikiQ());

    outP4.close();

    //generowanie wykresow
    int result = system("python3 ../wykresy.py"); // Use python or python3 depending on your setup
    if (result != 0)
    {
        std::cerr << "Blad podczas generowania wykresu." << std::endl;
    }

    return 0;
}