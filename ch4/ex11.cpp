// Exercise 4.11: computer first 100 primes
#include "std_lib_facilities.h"
int main()
{
     constexpr int bound = 100;
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
