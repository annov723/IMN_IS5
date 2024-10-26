#include "zad1.h"

vector<double> Zad1::metodaPicarda()
{
    vector<double> u;
    u.push_back(u0);

    for(double t = 0; t < t_max; t += delta_t)
    {
        double u_i = u.end()[-1];
        double u_i1 = 0;
        for (int j = 0; j < mi_max; j++)
        {
            u_i1 = u.end()[-1] + delta_t / 2 * ((alfa * u.end()[-1] - beta * u.end()[-1] * u.end()[-1])+((alfa * u_i - beta * u_i * u_i)));
            if (abs(u_i1 - u_i) < TOL)
            {
                break;
            }
            u_i = u_i1;
        }
        u.push_back(u_i1);
    }
    return u;
}

vector<double> Zad1::metodaNewtona()
{
    vector<double> u;
    u.push_back(u0);

    for(double t = 0; t < t_max; t += delta_t)
    {
        double u_i = u[t];
        double u_i1 = 0;
        for (int j = 0; j < mi_max; j++)
        {
            u_i1 = u_i - (u_i - u.end()[-1] - delta_t / 2. * ((alfa * u.end()[-1] - beta * u.end()[-1] * u.end()[-1]) + (alfa * u_i - beta * u_i * u_i))) / (1. - delta_t / 2. * (alfa - 2. * beta * u_i));
            if (abs(u_i1 - u_i) < TOL)
            {
                break;
            }
            u_i = u_i1;
        }
        u.push_back(u_i1);
    }
    return u;
}

vector<double> Zad1::getZ(vector<double> u)
{
    vector<double> z;
    for (int i = 0; i < u.size(); i++)
    {
        z.push_back(N - u[i]);
    }
    return z;
}



vector<double> Zad1::niejawnaMetodaRK2(){
    vector<double> u;
    u.push_back(u0);

    for(double t = 0; t < t_max; t += delta_t)
    {
        double u1_i = u.end()[-1];
        double u2_i = u.end()[-1];
        for (int j = 0; j < mi_max; j++)
        {
            double m11 = 1. - delta_t * A[0][0] * ( alfa - 2. * beta * u1_i);
            double m12 = -delta_t * A[0][1] * (alfa - 2. * beta * u2_i);
            double m21 = -delta_t * A[1][0] * (alfa - 2. * beta * u1_i);
            double m22 = 1. - delta_t * A[1][1] * (alfa - 2. * beta * u2_i);

            double F1 = u1_i - u.end()[-1] - delta_t * (A[0][0] * (alfa * u1_i - beta * u1_i * u1_i) + A[0][1] * (alfa * u2_i - beta * u2_i * u2_i));
            double F2 = u2_i - u.end()[-1] - delta_t * (A[1][0] * (alfa * u1_i - beta * u1_i * u1_i) + A[1][1] * (alfa * u2_i - beta * u2_i * u2_i));

            double delta_u1 = (F2 * m12 - F1 * m22) / (m11 * m22 - m12 * m21);
            double delta_u2 = (F1 * m21 - F2 * m11) / (m11 * m22 - m12 * m21);

            
            u1_i = u1_i + delta_u1;
            u2_i = u2_i + delta_u2;
        }
        double un = u.end()[-1] + delta_t * (b * f(t + c * delta_t, u1_i) + b * f(t + c * delta_t, u2_i));
        u.push_back(un);
    }
    return u;
}

double Zad1::f(double t, double u)
{
    return (beta * N - gamma) * u - beta * u * u;
}