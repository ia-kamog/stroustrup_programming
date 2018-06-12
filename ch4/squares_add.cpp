// calculate the table of squares 0-99 using addition
#include "std_lib_facilities.h"

int square(int);

int main()
{
     for (int i = 0; i < 99; ++i)
	  cout << i << '\t' << square(i) << '\n';
}

// calculate square of x
int square(int x)
{
     if (x < 0)
	  x = -x;
     int result = 0;
     for (int i = 0; i < x; ++i)
	  result += x;
     return result;
}
