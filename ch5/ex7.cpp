// Exercise 5.7.
// Solve a quadratic equation.
// If the equation doesn't have roots, report.

#include "std_lib_facilities.h"

static void print_roots(double a, double b, double c);

int main()
{
     double a, b, c;
     cin >> a >> b >> c;
     print_roots(a,b,c);
}

static void
print_roots(double a, double b, double c)
{
     double D = b*b - 4*a*c;
     double p = -b / (2*a);
     if (D > 0) {
	  double d = sqrt(D) / (2*a);
	  cout << p - d << ' ' << p + d;
     } else if (D == 0) {
	  cout << p;
     } else
	  cout << "No roots";
     cout << '\n';
}
	       
