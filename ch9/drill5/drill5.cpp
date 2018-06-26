#include <iostream>
#include "date.h"
using namespace std;

int main()
{
     Date today {1988, Month::feb, 29};
     Date tomorrow = today;
     tomorrow.add_year(1000);
     cout << "today: " << today << '\n'
	  << "tomorrow: " << tomorrow << '\n';
}
