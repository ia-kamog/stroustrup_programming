/* Exercise 8.5
   Test functions reversing vectors of ints. */
#include "reverse.h"
#include "print.h"
#include <vector>

using namespace std;

static void init(vector<int>& v);

int main()
{
     constexpr size_t size1 = 4;
     constexpr size_t size2 = 5;
     vector<int> v1(size1);
     vector<int> v2(size2);

     init(v1);
     init(v2);
     vector<int> v1_r = reverse(v1);
     vector<int> v2_r = reverse(v2);
     reverse_inplace(v1);
     reverse_inplace(v2);
     print("v1", v1);
     print("v2", v2);
     print("v1_r", v1_r);
     print("v2_r", v2_r);
}

void init(vector<int>& v)
{
     for (size_t i = 0; i < v.size(); ++i)
	  v[i] = i;
}
