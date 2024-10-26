#ifndef ZAD1_H
#define ZAD1_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Zad1 {
public:
    vector<double> metodaPicarda();
    vector<double> metodaNewtona();
    vector<double> getZ(vector<double> u);

    vector<double> niejawnaMetodaRK2();
    double f(double t, double u);

private:
    double beta = 0.001;
    double N = 500.;
    double gamma = 0.1;
    double t_max = 100.;
    double delta_t = 0.1;
    double u0 = 1.;
    double TOL = 1e-6;
    double mi_max = 20.;
    double alfa = beta * N - gamma;

    vector<vector<double>> A = {{1. / 4., 1. / 4. - sqrt(3.) / 6.}, {1. / 4. + sqrt(3.) / 6., 1. / 4.}};
    double a = 1. / 2.;
    double b = 1.;
    double c = 1. /2.;
};

#endif