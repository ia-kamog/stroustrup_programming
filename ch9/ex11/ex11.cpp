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
     int y, m, d;
     cin  >> y >> m >> d;
     Date today {y, Month(m), d};
     Date tomorrow = today;
     tomorrow.add_day(1);
     info("today", today);
     info("tomorrow", tomorrow);
}
