// Exercise 5.3
// Simple program to convert Celsius to Kelvin
// Give error when the input is impossible temperature
#include "std_lib_facilities.h"

double ctok(double c)
{
     double k = c + 273.15;
     return k;
}

int main()
{
     double c = 0;
     cin >> c;
     double k = ctok(c);
     if (k > 0)
	  cout << k << '\n';
     else {
	  cerr << "Impossible temperature: " << c << " Celsius\n";
	  return 1;
     }
}
