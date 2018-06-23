/* Exercise 8.11
   Get statistical summary of a sequence of doubles. */

#include "stat.h"
#include <iostream>
#include <vector>

using namespace std;

static void print_summary(const Stat_desc&);

int main()
{
     vector<double> v;
     for (double x; cin >> x;)
	  v.push_back(x);
     Stat_desc d = get_stat_desc(v);
     print_summary(d);
}

void print_summary(const Stat_desc& d)
{
     cout << "min    = " << d.min << '\n'
	  << "max    = " << d.max << '\n'
	  << "mean   = " << d.mean << '\n'
	  << "median = " << d.median << '\n';
}
