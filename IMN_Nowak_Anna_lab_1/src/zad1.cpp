#include "zad1.h"

Zad1::Zad1(double _y0, double _lambda, double _t[2], double _deltaT) {
    y0 = _y0;
    lambda = _lambda;
    t[0] = _t[0];
    t[1] = _t[1];
    deltaT = _deltaT;
}

vector<double> Zad1::MetodaJawnaEulera() {
    double y = y0;
    double krok = t[0];
    vector<double> wyniki;

    while (krok <= t[1]) {
        wyniki.push_back(y);
        y = y + deltaT * (lambda * y);
        krok += deltaT;
    }
    return wyniki;
}

vector<double> Zad1::MetodaRK2() {
    double y = y0;
    double krok = t[0];
    vector<double> wyniki;

    while (krok <= t[1]) {
        wyniki.push_back(y);
        double k1 = lambda * y;
        double k2 = lambda * (y + deltaT * k1);
        y = y + deltaT / 2. * (k1 + k2);
        krok += deltaT;
    }
    return wyniki;
}

vector<double> Zad1::MetodaRK4() {
    double y = y0;
    double krok = t[0];
    vector<double> wyniki;

    while (krok <= t[1]) {
        wyniki.push_back(y);
        double k1 = lambda * y;
        double k2 = lambda * (y + deltaT / 2. * k1);
        double k3 = lambda * (y + deltaT / 2. * k2);
        double k4 = lambda * (y + deltaT * k3);
        y = y + deltaT / 6. * (k1 + 2. * k2 + 2. * k3 + k4);
        krok += deltaT;
    }
    return wyniki;
}