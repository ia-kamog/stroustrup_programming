// Exercise 4.16: calculate the mode of a number sequence
#include "std_lib_facilities.h"
int main()
{
     vector<int> values;
     for (int value; cin >> value;)
	  values.push_back(value);
     if (values.size() == 0)
	  cout << "Mode of empty sequence is undefined\n";
     else {
	  sort(values);
	  int x = values[0];
	  int xcount = 1;
	  int y = values[0];
	  int ycount = 1;
	  for (int i = 1; i < values.size(); ++i) {
	       if (y == values[i])
		    ++ycount;
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

	  cout << "Mode: " << x << '\n';
     }
}
