#include "print.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(const string& label, const vector<size_t>& v)
{
     cout << label << " {";
     if (v.size() > 0) {
	  for (size_t i = 0; i < v.size()-1; ++i)
	       cout << v[i] << ", ";
	  cout << v[v.size()-1];
     }
     cout << "}\n";
}
