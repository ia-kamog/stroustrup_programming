#include "print.h"
#include "../std_lib_facilities.h"
void print(const string& label, const vector<int>& v)
{
     cout << label << " {";
     if (v.size() > 0) {
	  for (size_t i = 0; i < v.size()-1; ++i)
	       cout << v[i] << ", ";
	  cout << v[v.size()-1];
     }
     cout << "}\n";
}
