// Exercise 4.9: calculate sum of power of 2 up to a given number
#include "std_lib_facilities.h"
int main()
{
     cout << "Enter the number interation (squares):\n";
     int iterations;
     cin >> iterations;
     if (iterations <= 0)
	  simple_error("Number of iterations must be a positive number.");

     double cur_d = 1, sum_d = 0;
     int cur_i = 1, sum_i = 0;
     for (int i = 1; i <= iterations; ++i) {
	  sum_d += cur_d;
	  sum_i += cur_i;
	  cur_i *= 2;
	  cur_d *= 2;
     }
     cout << "Double sum: " << sum_d
	  << "\nInt sum: " << sum_i << '\n';
}
