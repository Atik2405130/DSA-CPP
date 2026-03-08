#include <iostream>
using namespace std;

void add(int A[][100], int B[][100], int C[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiply(int A[][100], int B[][100], int C[][100], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int C11[100][100] = {0}, C12[100][100] = {0}, C21[100][100] = {0}, C22[100][100] = {0};

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }

    int M1[100][100] = {0}, M2[100][100] = {0}, M3[100][100] = {0}, M4[100][100] = {0};
    int M5[100][100] = {0}, M6[100][100] = {0}, M7[100][100] = {0}, M8[100][100] = {0};

    multiply(A11, B11, M1, mid);
    multiply(A12, B21, M2, mid);
    multiply(A11, B12, M3, mid);
    multiply(A12, B22, M4, mid);
    multiply(A21, B11, M5, mid);
    multiply(A22, B21, M6, mid);
    multiply(A21, B12, M7, mid);
    multiply(A22, B22, M8, mid);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
        {
            C11[i][j] = M1[i][j] + M2[i][j];
            C12[i][j] = M3[i][j] + M4[i][j];
            C21[i][j] = M5[i][j] + M6[i][j];
            C22[i][j] = M7[i][j] + M8[i][j];
        }

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
}

int main()
{
    int n;
    cin >> n;

    int A[100][100], B[100][100], C[100][100] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    multiply(A, B, C, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}