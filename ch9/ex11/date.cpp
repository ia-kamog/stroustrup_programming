/* Drill 9.5
   Date class from 9.7.4 */
#include "date.h"
#include <array>
#include <iostream>
#include <utility>

using namespace std;

Month operator++(Month& m)
{
     if (m == Month::dec)
	  m = Month::jan;
     else
	  m = Month(int(m)+1);
     return m;
}

constexpr bool leap_year(int y) { return y%4==0 && (y%400==0 || y%100!=0); }

constexpr int days_in_month(int y, Month m)
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

constexpr bool valid_date(int y, Month m, int d)
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

void Date::add_month(int n)
{
     for (int i = 1; i <= n; ++i)
	  add_day(days_in_month(y,m));
}

void Date::add_year(int n)
{
     for (int i = 1; i <= n; ++i)
	  add_month(int(Month::dec));
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

ostream& operator<<(ostream& os, const Date& d)
{
     return os << '(' << d.year()
	       << ',' << int(d.month())
	       << ',' << d.day() << ')';
}

bool operator<(const Date& d1, const Date& d2)
{
     if (d1.year() < d2.year())
	  return true;
     else if (d2.year() > d2.year())
	  return false;
     else if (d1.month() < d2.month())
	  return true;
     else if (d1.month() > d2.month())
	  return false;
     else if (d1.day() < d2.day())
	  return true;
     else
	  return false;
}

int operator-(Date d1, Date d2)
{
     int d = 0;
     bool minus = false;
     if (d1 < d2) {
	  swap(d1, d2);
	  minus = true;
     }
     while (d1 != d2) {
	  d2.add_day(1);
	  ++d;
     }
     return minus ? -d : d;
}

bool operator==(const Date& d1, const Date& d2)
{
     return d1.year() == d2.year() &&
	  d1.month() == d2.month() &&
	  d1.day() == d2.day();
}

bool operator!=(const Date& d1, const Date& d2)
{
     return !(d1 == d2);
}

Weekday weekday(const Date& d)
{
     static const Date ref {2018, Month::jun, 25};
     int dif = (d - ref)%7;
     if (dif<0) dif += 7;
     return Weekday(dif);
}

Date next_workday(const Date& d)
{
     Weekday w = weekday(d);
     Date r{d};
     switch (w) {
     case Weekday::sat:
	  r.add_day(2);
	  break;
     case Weekday::sun:
	  r.add_day(1);
	  break;
     default:
	  r.add_day(1);
	  break;
     }
     return r;
}

int week_of_year(const Date& d)
{
     Date x{d.year(), Month::jan, 1};
     return (d-x)/7+1;
}

std::ostream& operator<<(std::ostream& os, Weekday w)
{
     constexpr array<const char*, 7>
	  names { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
     return os << names[size_t(w)];
}
