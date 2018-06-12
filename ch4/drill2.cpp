// Drill 2: read two integers in a while loop
// and sort them
#include "std_lib_facilities.h"

int main()
{
     int a, b;
     while (cin >> a >> b) {
	  if (a > b) {
	       int t = a;
	       a = b;
	       b = t;
	  }
	  cout << "the larger value is: " << b << '\n';
	  cout << "the smaller value is: " << a << '\n';
     }
}
