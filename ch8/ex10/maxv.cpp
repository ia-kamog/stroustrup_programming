#include "maxv.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

double maxv(const vector<double>& v)
{
     if (v.size() == 0)
	  throw invalid_argument("empty vector to maxv");
     double m = v[0];
     for (auto x : v)
	  m = max(m, x);
     return m;
}
