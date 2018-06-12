// Exercise 5.6
// Convert temperature in Celsius to Fahrenheit and
// in Fahrenheit to Celsius

#include "std_lib_facilities.h"

constexpr double F_in_C = 9.0 / 5.0;
constexpr double zeroC_in_F = 32.0;

static double ftoc(double);
static double ctof(double);

struct Bad_temp { double temp; char unit; };

int main()
{
     double t, r;
     char unit, ounit;

     cin >> t;
     cin >> unit;
     switch (unit) {
     case 'C': case 'c':
	  r = ctof(t);
	  ounit = 'F';
	  break;
     case 'F': case 'f':
	  r = ftoc(t);
	  ounit = 'C';
	  break;
     default:
	  cerr << "Bad unit: " << unit << '\n';
	  return 1;
     }
     cout << r << ounit << '\n';
     return 0;
}

double ftoc(double f)
{
     return (f-zeroC_in_F)/F_in_C;
}

double ctof(double c)
{
     return F_in_C*c + zeroC_in_F;
}
