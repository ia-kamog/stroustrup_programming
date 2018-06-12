// Drill 6: read doubles in a while loop, noting largest and smallest elements
#include "std_lib_facilities.h"

int main()
{
     double a;
     double smallest;
     double largest;
     bool first = true;
     while (cin >> a) {
	  if (first) {
	       smallest = largest = a;
	       first = false;
	  }
	  cout << a;
	  if (a >= largest) {
	       cout << " The largest so far.";
	       largest = a;
	  }
	  if (a <= smallest) {
	       cout << " The smallest so far.";
	       smallest = a;
	  }
	  cout << '\n';
     }
}
