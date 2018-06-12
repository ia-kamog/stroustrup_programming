// Exercise 5.10.
// Compute the sum of first N real numbers.

#include "std_lib_facilities.h"

int main() try
{
     cout << "Please enter the number of values you want to sum:\n";
     int N;
     cin >> N;
     if (N < 0)
	  error("Number of elements to sum must be non-negative.");

     cout << "Please enter some integers (press '|' to stop):\n";
     vector<double> v;
     for (double x; cin>>x;)
	  v.push_back(x);

     if (N > v.size())
	  error("Not enough integers!");

     double s = 0;
     vector<double> diff(N-1);

     cout << "The sum of the first " << N << " numbers ( ";
     for (int i = 0; i < N; ++i) {
	  cout << v[i] << ' ';
	  s += v[i];
	  if (i > 0)
	       diff[i-1] = v[i] - v[i-1];
     }
     cout << ") is " << s << ".\n";
     cout << "Differences are ( ";
     for (double d : diff)
	  cout << d << ' ';
     cout << ").\n";
} catch (exception& e) {
     cout << e.what() << '\n';
     return 1;
}
