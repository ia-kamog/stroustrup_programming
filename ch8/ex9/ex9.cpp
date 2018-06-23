/* Exercise 8.9
   Calculate total prices from weights and prices */
#include "total_sum.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
     vector<double> prices;
     vector<double> weights;

     double p, w;
     while (cin >> p >> w) {
	  prices.push_back(p);
	  weights.push_back(w);
     }

     double total = total_sum(prices, weights);
     cout << total << '\n';
}
