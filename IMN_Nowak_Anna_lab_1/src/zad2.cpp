#include "zad2.h"

Zad2::Zad2(double _wspolczynnik) {
    wv = _wspolczynnik * w0;
    V = 10. * sin(wv * t[0]);
    MetodaRK4();
}

void Zad2::MetodaRK4(){
    double krok = t[0];

    while (krok <= t[1]) {
        wynikiQ.push_back(Q);
        wynikiI.push_back(I);

        double k1Q = I;
        double k1I = V / L - Q / (L * C) - R * I / L;

        V = 10. * sin(wv * (krok + deltaT / 2.));

        double k2Q = I + deltaT / 2. * k1I;
        double k2I = V / L - (Q + deltaT / 2. * k1Q) / (L * C) - R / L * (I + deltaT / 2. * k1I);

        double k3Q = I + deltaT / 2. * k2I;
        double k3I = V / L - (Q + deltaT / 2. * k2Q) / (L * C) - R / L * (I + deltaT / 2. * k2I);

        V = 10. * sin(wv * ( krok + deltaT ));

        double k4Q = I + deltaT * k3I;
        double k4I = V / L - (Q + deltaT * k3Q) / (L * C) - R / L * (I + deltaT * k3I);

        Q = Q + deltaT / 6. * (k1Q + 2. * k2Q + 2. * k3Q + k4Q);
        I = I + deltaT / 6. * (k1I + 2. * k2I + 2. * k3I + k4I);

        
        krok += deltaT;
    }
}