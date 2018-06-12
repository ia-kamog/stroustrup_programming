// Exercise 4.14: calculate primes between 1 and a given number using
// Sieve of Eratosthenes
#include <vector>
#include <iostream>
using namespace std;
int main()
{
     constexpr int start = 2;
     cout << "Enter the largest number to check:\n";
     int max;
     cin >> max;
     max--;
     if (max < 0)
	  return 1;
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
