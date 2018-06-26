/* Drill 9.1
   Date class from par. 9.4.1 */
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

void init_date(Date& dd, int y, int m, int d)
{
     if (valid_date(y, m, d)) {
	  dd.d = d;
	  dd.m = m;
	  dd.y = y;
     } else
	  throw Date::Invalid_date{};
}

void add_day(Date& dd, int n)
{
     int md;
     while (n + dd.d > (md=days_in_month(dd.y,dd.m))) {
	  n -= md;
	  if (dd.m == 12) {
	       dd.y = (dd.y==-1) ? 1 : dd.y+1;
	       dd.m = 1;
	  } else
	       dd.m++;
     }
     // n + dd.d <= md
     dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
     return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
