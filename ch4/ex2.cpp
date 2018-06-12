// Exercise 4.2: compute mean and median temperatures
#include "std_lib_facilities.h"
int main()
{
     vector<double> temps;
     for (double temp; cin >> temp; )
	  temps.push_back(temp);
     
     // compute mean temperature
     double sum = 0;
     for (int x : temps) sum += x;
     cout << "Average temperature: " << sum/temps.size() << '\n';

     // compute median temperature
     sort(temps);
     double median;
     if (temps.size() % 2 == 0)
	  median = (temps[temps.size()/2]+temps[temps.size()/2-1])/2;
     else
	  median = temps[temps.size()/2];
     cout << "Median temperature: " << median << '\n';
}
