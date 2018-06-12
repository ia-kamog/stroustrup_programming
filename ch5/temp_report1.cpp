// find highest, lowsest, and average temperature in the input
#include "std_lib_facilities.h"

int main()
{
     vector<double> temps;		// temperatures

     for (double temp; cin>>temp;)	// read and put into temps
	  temps.push_back(temp);

     double sum = 0;
     double high_temp = 0;
     double low_temp = 0;

     for (double x : temps)
     {
	  if (x>high_temp) high_temp = x;	// find high
	  if (x<low_temp) low_temp = x;		// find low
	  sum += x;
     }

     cout << "High temperature: " << high_temp << '\n'
	  << "Low temperature: " << low_temp << '\n'
	  << "Average temperature: " << sum/temps.size() << '\n';
}
