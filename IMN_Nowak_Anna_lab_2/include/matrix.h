#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;

namespace Matrix
{
    vector<vector<double>> get_matrix_A(vector<double> X, const int n);
    vector<double> get_matrix_Y(vector<vector<double>> A, vector<double> C, const int n);

    void print(vector<vector<double>> M, string title);
    void print(vector<double> V, string title);

    void write_to_file(ofstream *of, vector<vector<double>> M);
    void write_to_file_pretty(ofstream *of, vector<vector<double>> M, const string title);
    void write_to_file(ofstream *of, vector<double> M);

    vector<double> random_vector(const int n);
    vector<vector<double>> get_random_sqr_matrix(const int n);
    vector<vector<double>> get_zero_matrix(const int n);
    vector<double> get_zero_vector(const int n);
    vector<vector<double>> get_identity_matrix(const int n);
    vector<double> get_zeros_n_one_matrix(const int n, const int i);

    vector<vector<double>> multiply_matrix_matrix(vector<vector<double>> A, vector<vector<double>> B, const int n);

    vector<vector<double>> copy_matrix(vector<vector<double>> A, const int n);
}

#endif