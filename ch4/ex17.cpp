// Exercise 4.17: calculate min, max, mode of a string sequence
#include "std_lib_facilities.h"
int main()
{
     vector<string> values;
     for (string value; cin >> value;)
	  values.push_back(value);
     if (values.size() == 0)
	  cout << "Mode of empty sequence is undefined\n";
     else {
	  sort(values);
	  string x = values[0];
	  int xcount = 1;
	  string y = values[0];
	  string max = values[0];
	  string min = values[0];
	  int ycount = 1;
	  for (int i = 1; i < values.size(); ++i) {
	       if (values[i] > max) max = values[i];
	       if (values[i] < min) min = values[i];
	       if (y == values[i])  ++ycount;
	       else {
		    if (ycount > xcount) {
			 x = y;
			 xcount = ycount;
		    }
		    y = values[i];
		    ycount = 1;
	       }
	  }
	  if (ycount > xcount)
	       x = y;
	  cout << "Mode: " << x << '\n'
	       << "Max: " << max << '\n'
	       << "Min: " << min << '\n';
     }
}
