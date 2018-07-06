#include "date.h"
#include "util.h"
#include <array>
#include <iostream>
#include <cmath>
#include <utility>

namespace Chrono {
    using namespace std;
    static const array<int, 12> month_ord
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    struct Date_p { int y; Month m; int d; };
    static const Date_p first_date{1970, Month::jan, 1};
    static bool operator<(const Date_p& d1, const Date_p& d2) {
	if (d1.y < d2.y)
	    return true;
	else if (d1.y > d2.y)
	    return false;
	else if (d1.m < d2.m)
	    return true;
	else if (d1.m > d2.m)
	    return false;
	else if (d1.d < d2.d)
	    return true;
	else
	    return false;
    }
    static int days_since_ny(const Date_p& d)
    {
	int cnt = month_ord[int(d.m)-1];
	if (d.m >= Month::feb && leap_year(d.y))
	    ++cnt;
	cnt += d.d;
	return cnt-1;
    }

    static int days_until_ny(const Date_p& d)
    {
	return 365+leap_year(d.y)-days_since_ny(d);
    }
    static long diff(const Date_p& d2, const Date_p& d1)
    {
	bool pos{true};
	const Date_p *dp2 = &d2, *dp1 = &d1;
	if (d2 < d1) {
	    pos = false;
	    swap(dp1, dp2);
	}
	int y1 = dp1->y, y2 = dp2->y;
	int diff = 0;
	if (y2 > y1)
	    diff = days_since_ny(*dp2) +
		  year_diff_days(y1+1, y2) +
		  days_until_ny(*dp1);
	else
	    diff = days_since_ny(*dp2) - days_since_ny(*dp1);
	return pos ? diff : -diff;
    }
    Date::Date(int yy, Month mm, int dd)
    {
	if (valid_date(yy, mm, dd)) {
	    days = diff(Date_p{yy,mm,dd},first_date);
	} else
	    throw Date::Invalid_date{};
    }

    Date& Date::operator++()
    {
	++days;
	return *this;
    }
    void Date::date(int& y, Month& m, int& d) const
    {
	y = first_date.y;
	m = first_date.m;
	d = first_date.d;
	if (days < 0)
	    for (long int i = days; i < 0; ++i)
		if (d == 1 && m == Month::jan) {
		    if (m == Month::jan)
			y = y == 1 ? -1 : y-1;
		    --m;
		    d = month_length(y, m);
		} else
		    ++d;
	else
	    for (long int i = days; i > 0; --i)
		if (d == month_length(y,m)) {
		    if (m == Month::dec)
			y = (y!=-1) ? y+1 : 1;
		    ++m;
		    d = 1;
		} else
		    ++d;
    }		    
    void Date::add_day(long n)
    {
	days += n;
    }
    
/*    void Date::add_month(int n)
    {
	int d, y;
	Month m;
	date(y,m,d);
	div_t dy = div(n, 12);
	add_year(dy.quot);
	if (dy.rem + int(m) > int(Month::dec))
	    ++y, m = Month::jan,
		dy.rem -= int(Month::dec) - int(m);
	m = Month(int(m) + dy.rem);
	int ml = month_length(y, m);
	if (d > ml)
	    ++m, d = d - ml;
    }

    void Date::add_within_year(int n)
    {
	for (int i = 0; i < n; ++i)
	    ++*this;
    }

    void Date::add_year(int n)
    {
        if (d == 29 && m == Month::feb && !leap_year(y+n))
	    d = 1, m = Month::mar;
	y += n;
	} */
}
