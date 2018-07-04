#include <array>
#include <ios>
#include <tuple>

#include "date.h"
#include "util.h"

namespace Chrono {
    using namespace std;
    using Util::mod_count;
    using Tup = tuple<int, Month, int>;

    static const array<char,12> month_lengths
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static const array<const char*, 7> weekday_names
    { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
    static const Date monday_ref
    {2018, Month::jun, 25};
    static const array<int, 12> month_ord
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    
    bool operator==(const Date&, const Date&);
    bool operator!=(const Date&, const Date&);
    bool operator<(const Date&, const Date&);
    long operator-(const Date&, const Date&);
    
    ostream& operator<<(ostream&, const Date&);
    istream& operator>>(std::istream&, Date&);
    ostream& operator<<(std::ostream&, Weekday);

    Date first_day_of_year(const Date&);
    int days_since_ny(const Date&);
    int days_until_ny(const Date&);
    int leap_days_count(int y1, int y2);
    int month_length(const Date&);
    int month_length(int y, Month);
    Date next_workday(const Date&);
    bool valid_date(int y, Month, int d);
    Weekday weekday(const Date&);
    int week_of_year(const Date&);

    bool operator==(const Date& d1, const Date& d2)
    {
	return Tup{d1.year(), d1.month(), d1.day()} ==
	    Tup{d2.year(), d2.month(), d2.day()};
    }

    bool operator!=(const Date& d1, const Date& d2)
    {
	return !(d1 == d2);
    }

    bool operator<(const Date& d1, const Date& d2)
    {
	using Tup = tuple<int, Month, int>;
	return Tup{d1.year(), d1.month(), d1.day()} <
	    Tup{d2.year(), d2.month(), d2.day()};
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
	return os << '(' << d.year()
		  << ',' << int(d.month())
		  << ',' << d.day() << ')';
    }

    istream& operator>>(istream& is, Date& date)
    {
	int y, m, d;
	char p1, c1, c2, p2;
	is >> p1 >> y >> c1 >> m >> c2 >> d >> p2;
	if (!is)
	    return is;
	if (p1 != '(' || c1 != ',' || c2 != ',' || p2 != ')') {
	    is.setstate(ios_base::failbit);
	    return is;
	}
	date = Date{y, Month(m), d};
	return is;
    }

    long operator-(const Date& d2, const Date& d1)
    {
	bool pos{true};
	const Date *dp2 = &d2, *dp1 = &d1;
	if (d2 < d1) {
	    pos = false;
	    swap(dp1, dp2);
	}
	int y1 = dp1->year(), y2 = dp2->year();
	int diff = 0;
	if (y2 > y1)
	    diff = days_since_ny(*dp2) +
		  year_diff_days(y1+1, y2) +
		  days_until_ny(*dp1);
	else
	    diff = days_since_ny(*dp2) - days_since_ny(*dp1);
	return pos ? diff : -diff;
    }

    ostream& operator<<(ostream& os, Weekday w)
    {
	return os << weekday_names[int(w)];
    }

    Date first_day_of_year(const Date& d)
    {
	return Date{d.year(), Month::jan, 1};
    }

    int days_since_ny(const Date& d)
    {
	int cnt = month_ord[int(d.month())-1];
	if (d.month() >= Month::feb && leap_year(d.year()))
	    ++cnt;
	cnt += d.day();
	return cnt-1;
    }

    int days_until_ny(const Date& d)
    {
	return 365+leap_year(d.year())-days_since_ny(d);
    }

    int leap_days_count(int y1, int y2)
    {
	return mod_count(4,y1,y2) -
	    mod_count(100,y1,y2) +
	    mod_count(400,y1,y2);
    }

    int month_length(const Date& d)
    {
	return month_length(d.year(),d.month());
    }

    int month_length(int y, Month m)
    {
	return (m==Month::feb && leap_year(y))?
	    29 : month_lengths[int(m)-1];
    }

    Date next_workday(const Date& d)
    {
	Weekday w = weekday(d);
	Date r{d};
	switch (w) {
	case Weekday::sat:
	    r.add_day(2);
	    break;
	default:
	    r.add_day(1);
	    break;
	}
	return r;
    }

    bool valid_date(int y, Month m, int d)
    {
	bool vy = y!=0;
	bool vm = Month::jan <= m && m <= Month::dec;
	if (vy && vm) {
	    int ml = month_length(y, m);
	    bool vd = 1 <= d && d <= ml;
	    return vd;
	} else {
	    return false;
	}
    }

    long year_diff_days(int y1, int y2)
    {
	return 365L*(y2-y1)+leap_days_count(y1,y2);
    }

    Weekday weekday(const Date& d)
    {
	int dif = (d - monday_ref)%7;
	if (dif<0) dif += 7;
	return Weekday(dif);
    }

    int week_of_year(const Date& d)
    {
	Date fy = first_day_of_year(d);
	Weekday wfy = weekday(fy);
	int fw  = int(first_day_of_week)-int(wfy);
	if (fw < 0)
	    fw += 7;
	int diff = days_since_ny(d) - fw;
	return (diff >= 0 ? diff+1 : 0)/7; 
    }
}
