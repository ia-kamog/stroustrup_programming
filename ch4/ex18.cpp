// Exercise 4.18: solve a quadratic equation
#include "std_lib_facilities.h"
int main()
{
     double a, b, c;
     cin >> a >> b >> c;
     double D = b*b - 4*a*c;
     if (D < 0)
	  cout << "no solutions\n";
     else {
	  double sD = sqrt(D);
	  cout << "x1=" << (-b+sD)/(2*a) << ' '
	       << "x2=" << (-b-sD)/(2*a) << '\n';
     }
}
