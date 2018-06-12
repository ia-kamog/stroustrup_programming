// Drill 2: read two doubles in a while loop
// and sort them, check for equality
#include "std_lib_facilities.h"

int main()
{
     double a, b;
     while (cin >> a >> b) {
	  if (a == b)
	       cout << "the number are equal: " << a << " == " << b << '\n';
	  else {
	       if (a > b) {
		    int t = a;
		    a = b;
		    b = t;
	       }
	       cout << "the larger value is: " << b << '\n';
	       cout << "the smaller value is: " << a << '\n';
	  }
     }
}
