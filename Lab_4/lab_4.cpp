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

//#define int ll
#define double long double

const long long arr = 250001;
const long long inf = 1e8+22;
const long long md = 1e9+7;

const  double eps = 0.0001;

const long long p = 31;
const long long b_base=1e6+1;


///Tsybick A. K-26 Lab-4 (¹ 1, 2)


/*

5 -6 20 -16
2 1 -10 4

*/

double A,B,C,D,E,F;

void show_equations()
{
    cout << "System : \n";

    if (A!=0)
    {
        cout << A << "X^3";
    }
    if (B!=0)
    {
        if (B>0)  cout << '+';
        cout << B << "x^2";
    }
    if (C!=0)
    {
        if (C>0)  cout << '+';
        cout << C << "x";
    }
    if (D!=0)
    {
        if (D>0)  cout << '+';
        cout << D;
    }
    if (E!=0)
    {
        if (E>0)  cout << '+';
        cout << E << "sin(x)";
    }
    cout << " = " << F  << "\n";

}

const double pi = 3.14159265359;

double cheb[11];

void cheb_count(double a, double b)
{
    for (int i = 1; i<=10; i++)
    {
      //  cout << ((2.0*i-1)/(20))*pi << ' ' << cos( ((2.0*i-1)/(20))*pi ) << " ! ";
        cheb[10-i+1] = (a+b)/2.0 + (1/2.0)*(b-a)*cos( ((2.0*i-1)/(20))*pi );
    }
}


double getf_x (double x)
{
    return A*x*x*x + B*x*x + C*x + D + E*(sin(x));
}

double f_x [11];
double fval_x [11];
double f_rec_x[10][10];

double calc_f_rec_x(int a, int b)
{
   // cout << a << ' ' << b << "  :  ";
    if (a == b) return f_rec_x[a][b] = fval_x[a];
    if (b-a == 1) return (fval_x[b] - fval_x[a])/(cheb[b]-cheb[a]);
    return f_rec_x[a][b] =  (calc_f_rec_x(a+1,b)-calc_f_rec_x(a,b-1))/(cheb[b]-cheb[a]);
}

const long long maxi = 20;

signed main()
{
    cout << "Ax^3 + Bx^2 + Cx + D + Esin(x) = F \n";
    cout << "Enter coefficients A,B,C,D,E,F: ";
    cin >> A >> B >> C >> D >> E >> F;
    show_equations();
    cout << "Enter the starting boundaries of the interpolation (l & r): \n";
    double l,r;
    cin >> l >> r;
    int t = 0;
    while (r-l > eps && t++ < maxi)
    {
        cout << l << ' ' << r << "\n";
        cheb_count(l,r);
        cout << "\n";
        for (int i = 1; i<=10; i++)
        {
            cout << cheb[i] << ' ';
            fval_x[i] = getf_x(cheb[i]);
        }
        cout << "\n";
        for (int i = 1; i<=10; i++)
        {
            cout << fval_x[i] << ' ';
        }
        cout << "\n";
        calc_f_rec_x(1,10);


       /* for (int i = 1; i<=10; i++)
        {
            for (int j = 1; j<=10; j++)
            {
                cout << f_rec_x[i][j] << ' ';
            }
            cout << "\n";
        }
        cout << "\n";

*/
        for (int i = 1; i<=10; i++)
        {
            double mult = 1;
            f_x[i] = fval_x[1];
            for (int j = 2 ;  j<=i; j++)
            {
                mult*= (fval_x[i]-fval_x[j]);
                f_x[i] += f_rec_x[1][j]*mult;
            }
        }

        double closest_x  = inf;
        int closest_i = -1;
        for (int i = 1; i<=10; i++)
        {
            cout << "p(" << cheb[i] << ") = " << f_x[i]  << "; \n";
           // cout << "f(" << cheb[i] << ") = " << fval_x[i]  << "; \n";
            if (fabs(F-fval_x[i]) < closest_x)
            {
                closest_x = fabs(F-fval_x[i]);
                closest_i = i;
            }
        }
        cout << "\n";
        if (closest_i == 1) r = cheb[2];
        if (closest_i == 10) l = cheb[9];
        if (closest_i > 1 && closest_i<10)
        {
            l = cheb[closest_i-1];
            r = cheb[closest_i+1];
        }
    }
    cout << "x = " << l;
    return 0;
}
