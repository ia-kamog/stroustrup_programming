#include "name_pairs.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Name_pairs::read_names()
{
     for (string s; cin >> s;) {
	  if (s == name_sentinel)
	       break;
	  if (s.size() > maxname)
	       maxname = s.size();
	  names.push_back(s);
     }
     ages.resize(names.size());
}

void Name_pairs::read_ages()
{
     for (size_t i = 0; i < names.size(); ++i) {
	  cout << names[i] << ": " << flush;
	  cin >> ages[i];
     }
}

void Name_pairs::print() const
{
     for (size_t i = 0; i < names.size(); ++i)
	  cout << setw(maxname) << names[i]
	       << ' '
	       << setw(5) << ages[i]
	       << '\n';
}

void Name_pairs::sort()
{
     for (size_t i = 1; i < names.size(); ++i) {
	  string cn = names[i];
	  double ca = ages[i];
	  size_t j = i;
	  while (1 <= j && names[j-1] > cn)
	       --j;
	  for (size_t k = i; k > j; --k) {
	       names[k] = names[k-1];
	       ages[k] = ages[k-1];
	  }
	  names[j] = cn;
	  ages[j] = ca;
     }
}
