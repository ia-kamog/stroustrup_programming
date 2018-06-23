#include "total_sum.h"
#include <vector>
#include <stdexcept>
using namespace std;
double total_sum(const vector<double>& prices,
		 const vector<double>& weights)
{
     if (prices.size() != weights.size())
	  throw invalid_argument("prices and weights must be of "
				 "the same length");
     double res = 0;
     for (size_t i = 0; i < prices.size(); ++i)
	  res += prices[i]*weights[i];
     return res;
}
