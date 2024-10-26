#ifndef ZAD1_H
#define ZAD1_H

#include <iostream>
#include <vector>

using namespace std;

class Zad1 {
public:
    Zad1(double _y0, double _lambda, double _t[2], double _deltaT);
    vector<double> MetodaJawnaEulera();
    vector<double> MetodaRK2();
    vector<double> MetodaRK4();

private:
    double y0;
    double lambda;
    double t[2];
    double deltaT;
};

#endif