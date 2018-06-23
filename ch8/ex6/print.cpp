#include "print.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static void print_string(const string& s)
{
     cout << '"' << s << '"';
}

void print(const string& label, const vector<string>& v)
{
     cout << label << " {";
     if (v.size() > 0) {
	  for (size_t i = 0; i < v.size()-1; ++i) {
	       print_string(v[i]);
	       cout << ", ";
	  }
	  print_string(v[v.size()-1]);
     }
     cout << "}\n";
}
