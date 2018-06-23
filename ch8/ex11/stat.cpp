#include "stat.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

static double median(const vector<double>& v)
{
     size_t n = v.size();
     if (n%2) return v[n/2];
     else return (v[n/2-1] + v[n/2])/2;
}

static double average(const vector<double>& v)
{
     double s = 0;
     for (auto x : v)
	  s += x;
     return s / v.size();
}

Stat_desc get_stat_desc(vector<double> data)
{
     if (data.size() == 0)
	  throw invalid_argument("empty data vector to get_stat_desc");

     sort(data.begin(), data.end());

     return { data[0], data[data.size()-1],
	     average(data), median(data) };
}
