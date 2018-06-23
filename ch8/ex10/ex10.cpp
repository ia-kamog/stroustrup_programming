/* Exercise 8.10
   Find maximal element in a vector */
#include "maxv.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
     vector<double> v;
     for (double d; cin >> d;)
	  v.push_back(d);
     cout << maxv(v) << '\n';
}
