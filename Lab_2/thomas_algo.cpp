#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
    int n, m;
    ifstream f("matrix.txt");
    f >> n;
    cout << "Number of equations = " << n << endl;
    cout << "Number of variables = " << n << endl;
    m = n + 1;
    double **A = new double *[n];
    for (int i = 0; i < n; i++)
        A[i] = new double[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> A[i][j];
        }
    }
    f.close();


    cout << "Matrix A: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    double y, a[n], B[n], x[n];
    y = A[0][0];
    a[0] = -A[0][1] / y;
    B[0] = A[0][m-1] / y;
    cout <<y <<' ' <<a[0] << ' ' <<B[0] <<endl;
    for (int i = 1; i < n; i++) {
     y = A[i][i] + A[i][i - 1] * a[i - 1];

     a[i] = -A[i][i + 1] / y;
     B[i] = (A[i][m-1] - A[i][i - 1] * B[i - 1]) / y;
     cout << "y" <<" = " << y << " a" << i <<" = "<<a[i] << " B" << i <<" = " <<B[i] <<endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i] * x[i + 1] + B[i];
    }
    cout <<endl <<"Result" <<endl;
    for (int i = 0; i < n; i++)
        cout << "x" << i << " = " << x[i] << "\n";
    cout << endl;

    return 0;
}
