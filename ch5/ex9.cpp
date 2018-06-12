// Exercise 5.9.
// Compute the sum of first N integers.

#include "std_lib_facilities.h"

int main() try
{
     cout << "Please enter the number of values you want to sum:\n";
     int N;
     cin >> N;
     if (N < 0)
	  error("Number of elements to sum must be non-negative.");

     cout << "Please enter some integers (press '|' to stop):\n";
     vector<int> v;
     for (int x; cin>>x;)
	  v.push_back(x);

     if (N > v.size())
	  error("Not enough integers!");

     int s = 0;

     cout << "The sum of the first " << N << " numbers ( ";
     for (int i = 0; i < N; ++i) {
	  cout << v[i] << ' ';
	  s = narrow_cast<int>(long(s)+long(v[i]));
     }
     cout << ") is " << s << ".\n";
} catch (exception& e) {
     cout << e.what() << '\n';
     return 1;
}
