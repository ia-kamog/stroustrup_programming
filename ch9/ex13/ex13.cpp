#include "rational.h"
#include <iostream>
using namespace std;
int main() try
{
     int a, b, c, d;
     cin >> a >> b >> c >> d;
     Rational r1{a,b}, r2{c,d};
     cout << r1 << "==" << r2 << ": " << (r1 == r2) << '\n'
	  << r1 << "+" << r2 << ": " << r1 + r2 << '\n'
	  << r1 << "-" << r2 << ": " << r1 - r2 << '\n'
	  << r1 << "*" << r2 << ": " << r1 * r2 << '\n'
	  << r1 << "/" << r2 << ": " << r1 / r2 << '\n'
	  << "double(" << r1 << "): " << double(r1) << '\n'
	  << "double(" << r2 << "): " << double(r2) << '\n';
}
catch (Rational::Division_by_zero& e)
{
     cerr << "Divivsion by zero!\n";
     return 1;
}
