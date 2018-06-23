#include "fib.h"
#include <vector>
#include <stdexcept>

using namespace std;

void fibonacci(int x, int y, vector<int>& v, unsigned n)
{
     v.resize(n);
     for (unsigned i = 0; i < n; i++) {
	  v[i] = x;
	  int t = x;
	  x = y, y = t + y;
     }
}
