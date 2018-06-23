#include "reverse.h"
#include <vector>
#include <utility>

using namespace std;

vector<int> reverse(const vector<int>& in)
{
     size_t sz = in.size();
     vector<int> out(sz);
     for (size_t i = 0; i < sz; ++i)
	  out[i] = in[sz-1-i];
     return out;
}

void reverse_inplace(vector<int>& v)
{
     size_t sz = v.size();
     for (size_t i = 0; i < sz/2; ++i)
	  swap(v[i], v[sz-1-i]);
}
