// Exercise 4.13: calculate primes between 1 and 100 using
// Sieve of Eratosthenes
#include <vector>
#include <iostream>
using namespace std;
int main()
{
     constexpr int start = 2;
     constexpr int max = 100-1;
     vector<bool> not_prime(max);
     
     for (int i = 0; i < max; ++i) {
	  if (!not_prime[i])
	       for (int j = 2*(i+start)-start; j < max; j += i+start)
		    not_prime[j] = true;
     }

     for (int i = 0; i < max; ++i)
	  if (!not_prime[i])
	       cout << i+start << ' ';
     cout << endl;
}
