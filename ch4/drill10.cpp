// Drill 10: calculate min, max, sum of lengths in in, cm, m, ft
#include "std_lib_facilities.h"
int main()
{
     constexpr double cm_per_m = 100;
     constexpr double cm_per_in = 2.54;
     constexpr double in_per_ft = 12;
     
     vector<double> values;
     double value;
     string unit = "";
     while (cin >> value >> unit) {
	  double value_in_meters;
	  if (unit == "m")
	       value_in_meters = value;
	  else if (unit == "cm")
	       value_in_meters = value/cm_per_m;
	  else if (unit == "in")
	       value_in_meters = value*cm_per_in/cm_per_m;
	  else if (unit == "ft")
	       value_in_meters = value*in_per_ft*cm_per_in/cm_per_m;
	  else {
	       cout << "Bad unit!\n";
	       continue;
	  }
	  values.push_back(value_in_meters);
     }
     
     if (values.size() == 0)
	  cout << "No values are entered!\n";
     else {
	  double sum {0};
	  double smallest {values[0]};
	  double largest {values[0]};
	  cout << "Values are (in meters):";
	  for (double x: values) {
	       sum += x;
	       if (x > largest)
		    largest = x;
	       if (x < smallest)
		    smallest = x;
	       cout << ' ' << x;
	  }
	  cout << "\nsum: " << sum
	       << "\nmax: " << largest
	       << "\nmin: " << smallest
	       << "\nnum: " << values.size() << '\n';
     }
}
