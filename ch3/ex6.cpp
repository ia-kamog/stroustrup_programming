// Exercise 3.6: order three integer values
#include "std_lib_facilities.h"

int main()
{
     cout << "Enter three integers\n";
     int i1, i2, i3;
     cin >> i1 >> i2 >> i3;
     if (i1 > i2)
	  swap(i1, i2);
     // i1 <= i2
     if (i2 > i3)
	  swap(i2, i3);
     // i1 <= i3, i2 <= i3
     if (i1 > i2)
	  swap(i1, i2);
     // i1 <= i2, i2 <= i3
     string sep = ", ";
     cout << i1 << sep << i2 << sep << i3 << '\n';
}
     
