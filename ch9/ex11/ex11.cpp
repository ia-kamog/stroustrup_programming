#include <iostream>
#include <string>
#include "date.h"

using namespace std;

static void info(string s, const Date& d)
{
     cout << s << ": " << d
	  << ' ' << weekday(d) << ' '
	  << next_workday(d) << ' '
	  << week_of_year(d) << '\n';
}

int main()
{
     Date today {1970, Month::feb, 28};
     Date tomorrow = today;
     tomorrow.add_day(2);
     info("today", today);
     info("tomorrow", tomorrow);
}
