// Exercise 3.5: calculate min, max, sum, difference, product
// and ration of two double-point floating values
#include "std_lib_facilities.h"

int main()
{
     cout << "Enter two double-point floating values\n";
     double val1, val2;
     cin >> val1 >> val2;
     double min, max, diff, prod, sum, ratio;
     if (val1 > val2) {
	  min = val2;
	  max = val1;
     } else {
	  min = val1;
	  max = val2;
     }
     diff = val1-val2;
     prod = val1*val2;
     sum = val1+val2;
     ratio = val1;
     ratio /= val2;
     cout << "min = " << min
	  << "\nmax = " << max
	  << "\nsum = " << sum
	  << "\ndiff = " << diff
	  << "\nprod = " << prod
	  << "\nratio = " << ratio
	  << '\n';
}
