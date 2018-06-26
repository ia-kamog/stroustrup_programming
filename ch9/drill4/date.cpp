/* Drill 9.4
   Date class from 9.7.1 */
#include "date.h"
#include <iostream>

using namespace std;

Month operator++(Month& m)
{
     if (m == Month::dec)
	  m = Month::jan;
     else
	  m = Month(int(m)+1);
     return m;
}

bool leap_year(int y) { return y%4==0 && y%100!=0; }

int days_in_month(int y, Month m)
{
     switch (m) {
     case Month::feb:
	  return leap_year(y) ? 29 : 28;
     case Month::apr: case Month::jun:
     case Month::sep: case Month::nov:
	  return 30;
     default:
	  return 31;
     }
}

bool valid_date(int y, Month m, int d)
{
     return y!=0 &&
	  Month::jan <= m && m <= Month::dec &&
	  1 <= d && d <= days_in_month(y, m);
}

Date::Date(int yy, Month mm, int dd)
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
	  if (++m == Month::jan)
	       y = y == -1 ? 1 : y + 1;
     }
     // n + d <= md
     d += n;
}

ostream& operator<<(ostream& os, Date& d)
{
     return os << '(' << d.year()
	       << ',' << int(d.month())
	       << ',' << d.day() << ')';
}
