#include <iostream>
#include "date.h"
using namespace std;

int main()
{
     Date today;
     init_date(today, 1978, 6, 28);
     Date tomorrow = today;
     add_day(tomorrow, 1);
     cout << "today: " << today << '\n'
	  << "tomorrow: " << tomorrow << '\n';
}
