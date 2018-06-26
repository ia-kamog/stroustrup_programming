#include <iostream>
#include "date.h"
using namespace std;

int main()
{
     Date today {1978, 6, 28};
     Date tomorrow = today;
     tomorrow.add_day(1);
     cout << "today: " << today << '\n'
	  << "tomorrow: " << tomorrow << '\n';
}
