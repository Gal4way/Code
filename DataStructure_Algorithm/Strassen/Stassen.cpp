#include <iostream>
#include <time.h>

using namespace std;

#define MAXVALUE 5

struct Matrix
{
    int n, m;
    int **v;
    
    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        v = new int *[n];
        for (int i = 0; i < n; i++)
            v[i] = new int [m];
        Clear();
    }


    void Clear()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                v[i][j] = 0;
    }

    void Rand()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                v[i][j] = rand() % MAXVALUE;
    }

    friend Matrix operator +(Matrix a, Matrix b)
    {
        Matrix c(max(a.n, b.n), max(a.m, b.m));
        for (int i = 0; i < c.n; i++)
            for (int j = 0; j < c.m; j++)
                c.v[i][j] = a.v[i][j] + b.v[i][j];
        return c;
    }
    
    friend Matrix operator -(Matrix a, Matrix b)
    {
        Matrix c(max(a.n, b.n), max(a.m, b.m));
        for (int i = 0; i < c.n; i++)
            for (int j = 0; j < c.m; j++)
                c.v[i][j] = a.v[i][j] - b.v[i][j];
        return c;
    }

    friend Matrix operator *(Matrix a, Matrix b)
    {
        Matrix c(a.n, b.m);
        for (int k = 0; k < a.m; k++)
            for (int i = 0; i < a.n; i++)
                for (int j = 0; j < b.m; j++)
                    c.v[i][j] += a.v[i][k] * b.v[k][j];
        return c;
    }

    friend ostream &operator<<(ostream &output, const Matrix &a)
    {
        for (int i = 0; i < a.n; i++)
        {
            for (int j = 0; j < a.m; j++)
                output << a.v[i][j] << " ";
            output << endl;
        }
    }
};

int times = 0;

Matrix Strassen(int n, Matrix A, Matrix B)
{
    if (n < 4) 
        return A * B;

    Matrix A11(n / 2, n / 2), B11(n / 2, n / 2);
    Matrix A12(n / 2, n / 2), B12(n / 2, n / 2);
    Matrix A21(n / 2, n / 2), B21(n / 2, n / 2);
    Matrix A22(n / 2, n / 2), B22(n / 2, n / 2);

    for (int i = 0; i < n / 2; i ++)
        for (int j = 0; j < n / 2; j++)
        {
            A11.v[i][j] = A.v[i][j];
            A12.v[i][j] = A.v[i][j + n / 2];
            A21.v[i][j] = A.v[i + n / 2][j];
            A22.v[i][j] = A.v[i + n / 2][j + n / 2];

            B11.v[i][j] = B.v[i][j];
            B12.v[i][j] = B.v[i][j + n / 2];
            B21.v[i][j] = B.v[i + n / 2][j];
            B22.v[i][j] = B.v[i + n / 2][j + n / 2];
        }
    
    Matrix P1(n / 2, n / 2), P2(n / 2, n / 2), P3(n / 2, n / 2);
    Matrix P4(n / 2, n / 2), P5(n / 2, n / 2), P6(n / 2, n / 2), P7(n / 2, n / 2);
    P1 = Strassen(n / 2, A11, B12 - B22);
    P2 = Strassen(n / 2, A11 + A12, B22);
    P3 = Strassen(n / 2, A21 + A22, B11);
    P4 = Strassen(n / 2, A22, B21 - B11);
    P5 = Strassen(n / 2, A11 + A22, B11 + B22);
    P6 = Strassen(n / 2, A12 - A22, B21 + B22);
    P7 = Strassen(n / 2, A11 - A21, B11 + B12);

    Matrix C11(n / 2, n / 2), C12(n / 2, n / 2), C21(n / 2, n / 2), C22(n / 2, n / 2);
    C11 = P4 + P5 + P6 - P2;
    C12 = P1 + P2;
    C21 = P3 + P4;
    C22 = P1 - P3 + P5 - P7;

    Matrix C(n, n);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
        {
            C.v[i][j] = C11.v[i][j];
            C.v[i][j + n / 2] = C12.v[i][j];
            C.v[i + n / 2][j] = C21.v[i][j];
            C.v[i + n / 2][j + n / 2] = C22.v[i][j];
        }

    return C;
}

int main()
{
    srand(time(0));
    int n = 16;
    Matrix a(n, n), b(n, n), c(n, n);
    a.Rand();
    b.Rand();
    cout << a;
    cout << b;

    int t0 = clock();

    c = a * b;
    cout << "朴素算法所得矩阵：" <<endl;
    cout << a * b;

    cout << "Strassen算法所得矩阵：" <<endl;
    cout << Strassen(n, a, b);
}
