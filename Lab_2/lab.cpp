#include <bits/stdc++.h>
#define elif else if
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(num) num.begin(),num.end()
#define files(num) freopen(num".in","r",stdin); freopen(num".out","w",stdout)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define double long double

const long long arr = 250001;
const long long inf = 1e8+22;
const long long md = 1e9+7;

const  double eps = 0.000001;

const long long p = 31;
const long long b_base=1e6+1;

const int n = 10;

double table[n+2][n+2];
double table_b[n+2];

void show_table()
{
    cout << " Table: \n";
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n+1; j++)
        {
            cout << table[i][j] << ' ';
            if (j == n)
                cout << " | ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void jacobi_calc()
{
   double* TempX = new double[n+2];
   double norm;
    double x[n+2];
    for (int i = 1; i <= n; i++) x[i] = 0.0;
do {
    for (int i = 1; i <= n; i++) {
      TempX[i] = table_b[i];
      for (int g = 1; g <= n; g++) {
        if (i != g)
          TempX[i] -= table[i][g] * x[g];
      }
      TempX[i] /= table[i][i];
    }
        norm = fabs(x[1] - TempX[1]);
    for (int h = 1; h <= n; h++) {
      if (fabs(x[h] - TempX[h]) > norm)
        norm = fabs(x[h] - TempX[h]);
      x[h] = TempX[h];
    }
  } while (norm > eps);
  delete[] TempX;

    for (int i = 1; i<=n; i++)
    {
        cout << "x" << i << " = " << x[i] << "\n";
    }
}

/*
1

3 1 -2 0 9
1 5 3 -4 20
0 3 -5 0 1
5 -7 0 10 -9

*/
/*
  3 2 0 0 0 0 0 0 0 0 1
  1 3 2 0 0 0 0 0 0 0 2
  0 1 3 2 0 0 0 0 0 0 3
  0 0 1 3 2 0 0 0 0 0 4
  0 0 0 1 3 2 0 0 0 0 5
  0 0 0 0 1 3 2 0 0 0 6
  0 0 0 0 0 1 3 2 0 0 7
  0 0 0 0 0 0 1 3 2 0 8
  0 0 0 0 0 0 0 1 3 2 9
  0 0 0 0 0 0 0 0 1 3 10
*/

signed main()
{
    cout << "Enter (1) or generate (2) a table? \n";
    int choosed_var;
    cin >> choosed_var;
    if (choosed_var == 1)
    {
        cout << "Enter table nxn (with b): \n";
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<= n+1; j++)
            {
                cin >> table[i][j];
            }
            table_b[i] = table[i][n+1];
        }
        show_table();
    }
    else if (choosed_var == 2)
    {
        srand(time(0));
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=n+1; j++)
            {
                if (rand()%2)
                    table[i][j] = (rand()%20-10);
                else
                    table[i][j] = 0;
                if (i == j)
                {
                    table[i][j] = rand()%10+1;
                    if (rand()%2) table[i][j] *=-1;
                }
            }
            table_b[i] = table[i][n+1];
        }
        show_table();
    }
    jacobi_calc();
    return 0;
}

