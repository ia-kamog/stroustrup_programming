/* Drill 9.2
   Date class from par 9.4.2 */
#include "date.h"
#include <iostream>

using namespace std;

bool leap_year(int y) { return y%4==0 && y%100!=0; }

int days_in_month(int y, int m)
{
     switch (m) {
     case 2:
	  return leap_year(y) ? 29 : 28;
     case 4: case 6: case 9: case 11:
	  return 30;
     default:
	  return 31;
     }
}

bool valid_date(int y, int m, int d)
{
     return y!=0 &&
	  1 <= m && m <= 12 &&
	  1 <= d && d <= days_in_month(y, m);
}

Date::Date(int yy, int mm, int dd)
{
     if (valid_date(yy, mm, dd)) {
	  d = dd;
	  m = mm;
	  y = yy;
     } else
	  throw Date::Invalid_date{};
}

void Date::add_day(int n)
{
     int md;
     while (n + d > (md=days_in_month(y,m))) {
	  n -= md;
	  if (m == 12) {
	       y = (y==-1) ? 1 : y+1;
	       m = 1;
	  } else
	       m++;
     }
     // n + d <= md
     d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
     return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
