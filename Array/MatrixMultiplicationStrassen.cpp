#include <iostream>
using namespace std;

void add(int A[][100], int B[][100], int C[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(int A[][100], int B[][100], int C[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[][100], int B[][100], int C[][100], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];

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

    int M1[100][100], M2[100][100], M3[100][100], M4[100][100];
    int M5[100][100], M6[100][100], M7[100][100];

    int T1[100][100], T2[100][100];

    sub(B12, B22, T1, mid);
    strassen(A11, T1, M1, mid);

    add(A11, A12, T1, mid);
    strassen(T1, B22, M2, mid);

    add(A21, A22, T1, mid);
    strassen(T1, B11, M3, mid);

    sub(B21, B11, T1, mid);
    strassen(A22, T1, M4, mid);

    add(A11, A22, T1, mid);
    add(B11, B22, T2, mid);
    strassen(T1, T2, M5, mid);

    sub(A12, A22, T1, mid);
    add(B21, B22, T2, mid);
    strassen(T1, T2, M6, mid);

    sub(A11, A21, T1, mid);
    add(B11, B12, T2, mid);
    strassen(T1, T2, M7, mid);

    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
        {
            C11[i][j] = M5[i][j] + M4[i][j] - M2[i][j] + M6[i][j];
            C12[i][j] = M1[i][j] + M2[i][j];
            C21[i][j] = M3[i][j] + M4[i][j];
            C22[i][j] = M5[i][j] + M1[i][j] - M3[i][j] - M7[i][j];
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

    int A[100][100], B[100][100], C[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    strassen(A, B, C, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}