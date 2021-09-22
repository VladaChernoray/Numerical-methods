#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

#define   f(x)   pow(x,3)-10*pow(x,2)+44*x+29
#define   g(x)   (-pow(x,3)+10*pow(x,2)-29)/44
/*#define f(x) pow(x,3)-x-1
#define g(x) pow((x+1), 1/3)*/


int main()
{
	int step_1 = 1, N;
	int count;
	float x0, x1, e;
	cout << setprecision(6) << fixed;
	cout << "Enter initial guess: ";
	cin >> x0;
	cout << "Enter tolerable error: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	cout << endl << "Fixed Point Iteration Method" << endl;
	do{
		x1 = g(x0);
		//x1 = x0 - ((pow(x0, 3) - x0 - 1) / (2 * pow(x0, 2) - 1));
		step_1 = step_1 + 1;
		if (fabs(f(x1)) <= e) {
			break;
		}
		cout << "Iteration_" << step_1 << "x1 = " << x1 << " and f(x1) = " << f(x1) << endl;
		int temp = x0;
		x0 = x1;
		//cout << step_1 << endl;
		count = step_1;

	} while (step_1 <= N);
	cout << endl << "Result is " << x0;
	cout << endl << "n = " << count << endl;

	int step_2 = 0;
	double a, b, c;
	cout << "Enter the left restriction: "; 
	cin >> a;
	cout << "Enter the right restriction: "; 
	cin >> b;
	cout << endl << "Dichotomy Method" << endl;
	do {
		c = (a + b) / 2;
		if (f(c) >= 0) {
			b = c;
		}
		else a = c;
		step_2 += 1;
		cout << "Iteration_" << step_2 << " x1 = " << c << " and f(x1) = " << f(c) << endl;
	}
	while (fabs(a - b) >= e);
	cout << "Result is " << c << endl;
	cout << "n = " << step_2 << endl;

	return(0);
}