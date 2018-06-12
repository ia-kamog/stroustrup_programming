// Exercise 5.4
// Simple program to convert Celsius to Kelvin
// 
#include "std_lib_facilities.h"

double ctok(double c)
{
     constexpr double zero_Celsius_in_Kelvin = 273.15;
     double k = c + zero_Celsius_in_Kelvin;
     if (k > 0)
	  return k;
     else
	  throw logic_error("Bad temperature");
}

int main()
     try {
	  double c = 0;
	  cin >> c;
	  double k = ctok(c);
	  cout << k << '\n';
     } catch (exception& e) {
	  cerr << e.what() << '\n';
	  return 1;
     }

