/* Exercise 8.6
   Test functions reversing vectors of strings. */
#include "reverse.h"
#include "print.h"
#include <vector>

using namespace std;

static void init(vector<string>& v);

int main()
{
     constexpr size_t size1 = 4;
     constexpr size_t size2 = 5;
     vector<string> v1(size1);
     vector<string> v2(size2);

     init(v1);
     init(v2);
     vector<string> v1_r = reverse(v1);
     vector<string> v2_r = reverse(v2);
     reverse_inplace(v1);
     reverse_inplace(v2);
     print("v1", v1);
     print("v2", v2);
     print("v1_r", v1_r);
     print("v2_r", v2_r);
}

void init(vector<string>& v)
{
     for (size_t i = 0; i < v.size(); ++i)
	  v[i] += char('a' + i);
}
