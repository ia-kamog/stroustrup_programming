// Drill 5: read two double in a while loop
// and sort them, checking equalities
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
	       if (b-a < 1.0/100.0)
		    cout << "the numbers are almost equal\n";
	  }
     }
}
