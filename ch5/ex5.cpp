// Exercise 5.4
// Simple program to convert Celsius to Kelvin and the opposite way
// Display error for impossible temperatures

#include "std_lib_facilities.h"

constexpr double zero_Celsius_in_Kelvin = 273.15;
struct Bad_temp { double temp; char unit; };

double ctok(double c)
{
     double k = c + zero_Celsius_in_Kelvin;
     if (k > 0)
	  return k;
     else
	  throw Bad_temp{c, 'C'};
}

double ktoc(double k)
{
     if (k <= 0) throw Bad_temp{k, 'K'};
     double c = k - zero_Celsius_in_Kelvin;
     return c;
}

int main() try
{
     double input;
     cin >> input;
     char unit;
     cin >> unit;
     double output;
	  
     switch (unit) {
     case 'C': case 'c':
	  output = ctok(input);
	  unit = 'K';
	  break;
     case 'K': case 'k':
	  output = ktoc(input);
	  unit = 'C';
	  break;
     default:
	  throw runtime_error("Bad unit: " + string{unit});
     }
     cout << output << unit << '\n';
} catch (Bad_temp& e) {
     cerr << "Impossible temperature: " << e.temp
	  << e.unit << '\n';
     return 1;
}
catch (exception& e) {
     cerr << e.what() << '\n';
     return 1;
}
