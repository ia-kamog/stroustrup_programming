// Exercise 4.12: computer first a given number primes
#include "std_lib_facilities.h"
int main()
{
     cout << "Enter the number of primes:\n";
     int bound;
     cin >> bound;
     if (bound <= 0)
	  simple_error("Number of primes must be positive");
     vector<int> primes = {2};
     for (int cur = 3; cur <= bound; ++cur) {
	  bool is_prime = true;
	  for (int i = 0; is_prime && primes[i]*primes[i] <= cur; ++i)
	       is_prime = (cur % primes[i] != 0);
	  if (is_prime)
	       primes.push_back(cur);
     }

     for (int x: primes)
	  cout << x << ' ';
     cout << endl;
}
