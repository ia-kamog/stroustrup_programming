#include "date.h"
#include "util.h"
#include <array>
#include <iostream>
#include <cmath>
#include <utility>

namespace Chrono {
    using namespace std;
    
    Date::Date(int yy, Month mm, int dd)
    {
	if (valid_date(yy, mm, dd)) {
	    d = dd;
	    m = mm;
	    y = yy;
	} else
	    throw Date::Invalid_date{};
    }

    Date& Date::operator++()
    {
	if (d == month_length(y, m)) {
	    ++m, d = 1;
	    y = m == Month::jan ? y+1 : y;
	} else {
	    ++d;
	}
	return *this;
    }
    
    void Date::add_day(long n)
    {
	int uny = days_until_ny(*this);
	if (n <= uny)
	    add_within_year(n);
	else {
	    n -= uny;
	    d = 1;
	    m = Month::jan;
	    ++y;
	    int dy = round(n / average_year);
	    int x;
	    while ((x=year_diff_days(y,y+dy)) > n)
		--dy;
	    y += dy;
	    n -= x;
	    add_within_year(n);	    
	}
    }
    
    void Date::add_month(int n)
    {
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
    }
}
