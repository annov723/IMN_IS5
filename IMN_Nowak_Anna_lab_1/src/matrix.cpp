#include "matrix.h"

vector<vector<double>> Matrix::get_matrix_A(vector<double> X, const int n)
{
    vector<vector<double>> A;
    vector<double> temp;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            temp.push_back(pow(X[row], col));
        A.push_back(temp);
        temp.clear();
    }
    return A;
}

vector<double> Matrix::get_matrix_Y(vector<vector<double>> A, vector<double> C, const int n)
{
    vector<double> Y;
    double temp = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            temp = temp + ((double)A[row][col] * C[col]);

        Y.push_back(temp);
        temp = 0;
    }
    return Y;
}

void Matrix::print(vector<vector<double>> M, string title)
{
    int n_col = M[0].size();
    int n_row = M.size();

    cout << title << endl;
    for (int row = 0; row < n_row; row++)
    {
        for (int col = 0; col < n_col; col++)
            cout << setw(20) << setprecision(6) << M[row][col];
        cout << endl;
    }
    cout << endl;
}

void Matrix::print(vector<double> V, string title)
{
    cout << title << endl;
    for (auto i : V)
        cout << setw(20) << i;
    cout << endl;
}

void Matrix::write_to_file(ofstream *of, vector<vector<double>> M)
{
    int n_col = M[0].size();
    int n_row = M.size();

    for (int row = 0; row < n_row; row++)
    {
        for (int col = 0; col < n_col; col++)
            *of << M[row][col] << " ";
    }
    *of << '\n';
}

void Matrix::write_to_file_pretty(ofstream *of, vector<vector<double>> M, const string title)
{
    int n_col = M[0].size();
    int n_row = M.size();

    *of << title << '\n';
    for (int row = 0; row < n_row; row++)
    {
        for (int col = 0; col < n_col; col++)
            *of << setw(15) << M[row][col] << " ";
        *of << '\n';
    }
    *of << '\n';
}

void Matrix::write_to_file(ofstream *of, vector<double> M)
{
    int n = M.size();
    for (int i = 0; i < n; i++)
        *of << setprecision(10) << M[i] << " ";
    *of << '\n';
}

vector<double> Matrix::random_vector(const int n)
{
    vector<double> temp;
    int check = rand() % 2;

    for (int i = 0; i < n; i++)
    {
        check = rand() % 2;
        double random = (double)rand() / 1000;
        random = random - ((int)random / 100) * 100;
        if (random == 0)
        {
            i--;
            continue;
        }
        if (check == 1)
            random = random * (-1);

        temp.push_back(random);
    }
    return temp;
}

vector<vector<double>> Matrix::get_random_sqr_matrix(const int n)
{
    vector<vector<double>> M;
    vector<double> temp;
    int check = rand() % 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check = rand() % 2;
            double random = (double)rand() / 1000;
            random = random - ((int)random / 100) * 100;
            if (random == 0)
            {
                i--;
                continue;
            }
            if (check == 1)
                random = random * (-1);

            temp.push_back(random);
        }
        M.push_back(temp);
        temp.clear();
    }
    return M;
}

vector<vector<double>> Matrix::get_zero_matrix(const int n)
{
    vector<vector<double>> M;
    vector<double> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(0);
        }
        M.push_back(temp);
    }
    return M;
}

vector<vector<double>> Matrix::get_identity_matrix(const int n)
{
    vector<vector<double>> m = get_zero_matrix(n);
    for (int i = 0; i < n; i++)
        m[i][i] = 1;
    return m;
}

vector<double> Matrix::get_zeros_n_one_matrix(const int n, const int i)
{
    vector<double> vec;
    for (int j = 0; j < n; j++)
    {
        if (j == i)
            vec.push_back(1);
        else
            vec.push_back(0);
    }
    return vec;
}

vector<vector<double>> Matrix::multiply_matrix_matrix(vector<vector<double>> A, vector<vector<double>> B, const int n)
{
    vector<vector<double>> multi = get_zero_matrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;

            for (int k = 0; k < n; k++)
                sum = sum + (A[i][k] * B[k][j]);
            multi[i][j] = sum;
        }
    }
    return multi;
}

vector<double> Matrix::get_zero_vector(const int n)
{
    vector<double> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(0);
    return vec;
}

vector<vector<double>> Matrix::copy_matrix(vector<vector<double>> A, const int n)
{
    vector<vector<double>> C = get_zero_matrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j];
        }
    }
    return C;
}