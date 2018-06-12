// calculate and print a table of squares 0-99
#include "std_lib_facilities.h"

int square(int);

int main()
{
     for (int i = 0; i<100; ++i)
	  cout << i << '\t' << square(i) << '\n';
}

int square(int x)
{
     return x*x;
}
