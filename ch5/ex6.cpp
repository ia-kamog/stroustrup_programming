// Exercise 5.6
// Convert temperature in Celsius to Fahrenheit and
// in Fahrenheit to Celsius

#include "std_lib_facilities.h"

// degrees of fahrenheit in a degree of celsius
constexpr double F_in_C = 9.0 / 5.0;
// 0 C on the Fahrenheit scale
constexpr double zeroC_in_F = 32.0;

static double ftoc(double);
static double ctof(double);

struct Bad_temp // thrown on bad temperature input
{
     double temp;
     char unit;
};

int main()
{
     double t, r;
     char unit, ounit;

     cin >> t >> unit;
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

//convert f in Fahrenheits to temperature in centigrades
double ftoc(double f)
{
     return (f-zeroC_in_F)/F_in_C;
}

//convert c in degrees Celsium to Fahrenheits
double ctof(double c)
{
     return F_in_C*c + zeroC_in_F;
}
