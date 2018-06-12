// Drill 7: read lengths in m, cm, in, ft, noting largest and smallest elements
#include "std_lib_facilities.h"

int main()
{
     constexpr double cm_per_m = 100;
     constexpr double cm_per_in = 2.54;
     constexpr double in_per_ft = 12;
     
     double value;
     double smallest;
     double largest;
     string unit = "";
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
}
