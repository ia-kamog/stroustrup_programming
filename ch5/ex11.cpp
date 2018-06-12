// Exercise 5.11.
// Print Fibonacci numbers.

#include "std_lib_facilities.h"

int main() try
{
     int a, b;
     a = 1; b = 1;
     while (true) {
	  cout << a << '\n';
	  b = narrow_cast<int>(long(a)+long(b));
	  a = b - a;
     }
} catch (exception& e) {
     cerr << "end\n";
     return 0;
}
