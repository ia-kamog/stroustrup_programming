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

ostream& operator<<(ostream& os, const Name_pairs& x)
{
     for (size_t i = 0; os && i < x.size(); ++i)
	  os << setw(16) << x.name(i)
	     << ' '
	     << setw(5) << x.age(i)
	     << '\n';
     return os;
}

void Name_pairs::sort()
{
     for (size_t i = 1; i < names.size(); ++i) {
	  string cn = names[i];
	  double ca = ages[i];
	  size_t j = i;
	  while (1 <= j &&
		 (names[j-1] > cn ||
		  (names[j-1] == cn && ages[j-1] > ca)))
	       --j;
	  for (size_t k = i; k > j; --k) {
	       names[k] = names[k-1];
	       ages[k] = ages[k-1];
	  }
	  names[j] = cn;
	  ages[j] = ca;
     }
}

bool operator==(Name_pairs& x, Name_pairs& y)
{
     if (x.size() != y.size())
	  return false;
     x.sort();
     y.sort();
     bool eq = true;
     for (size_t i = 0; eq && i < x.size(); ++i)
	  eq = eq && x.name(i)==y.name(i) && x.age(i)==y.age(i);
     return eq;
}

bool operator!=(Name_pairs& x, Name_pairs& y)
{
     return !(x==y);
}
