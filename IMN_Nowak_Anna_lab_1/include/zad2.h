#ifndef ZAD2_H
#define ZAD2_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Zad2
{
public:
    Zad2(double _wspolczynnik);
    void MetodaRK4();
    vector<double> getWynikiI() { return wynikiI; }
    vector<double> getWynikiQ() { return wynikiQ; }

private:
    double deltaT = 0.0001;
    double R = 100.;
    double L = 0.1;
    double C = 0.001;
    double w0 = 1. / sqrt(L * C);
    double T0 = 2. * M_PI / w0;
    double t[2] = {0., 4. * T0};
    double Q = 0.;
    double I = 0.;
    double V;
    double wv;

    vector<double> wynikiI;
    vector<double> wynikiQ;
};

#endif