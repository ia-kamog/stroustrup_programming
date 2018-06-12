// Drill 9: read lengths in m, cm, in, ft, noting largest and smallest elements
// report summary: sum, smallest, largest, number of values
#include "std_lib_facilities.h"

int main()
{
     constexpr double cm_per_m = 100;
     constexpr double cm_per_in = 2.54;
     constexpr double in_per_ft = 12;

     int count = 0;
     double value = 0;
     double smallest = 0;
     double largest = 0;
     string unit = "";
     double sum = 0;
     bool first = true;
     
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
	  ++count;
	  sum += value_in_meters;
	  if (first) {
	       smallest = largest = value_in_meters;
	       first = false;
	  }
	  cout << value << unit << " == " << value_in_meters << "m";
	  if (value_in_meters >= largest) {
	       cout << " The largest so far.";
	       largest = value_in_meters;
	  }
	  if (value_in_meters <= smallest) {
	       cout << " The smallest so far.";
	       smallest = value_in_meters;
	  }
	  cout << '\n';
     }
     cout << "Sum: " << sum << "m\n"
	  << "Max: " << largest << "m\n"
	  << "Min: " << smallest << "m\n";
}
