// Exerice 3.8: test if an integer is even
#include "std_lib_facilities.h"
int main()
{
     cout << "Enter an integer value\n";
     int i;
     cin >> i;
     string res;
     if (i%2 == 0)
	  res = "even";
     else
	  res = "odd";
     cout << "The value " << i << " is an " << res << " number.\n";
}
