#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "date.h"

using namespace std;
using namespace Chrono;

// static void info(string s, const Date& d)
// {
//     cout << s << ": " << d
// 	 << ' ' << weekday(d) << ' '
// 	 << next_workday(d) << ' '
// 	 << week_of_year(d) << '\n';
// }

long year_diff_simple(int y1, int y2)
{
    bool neg = false;
    if (y2 < y1)
	neg = true, swap(y1, y2);
    long d = 0;
    for (; y1 < y2; ++y1)
	d += 365 + leap_year(y1);
    return neg ? -d : d;
}

void year_diff_test()
{
    bool r = false;
    vector<int> y1 = { 1560, 2008, 2000, 1991, 1800, 2018 };
    vector<int> y2 = { 1600, 2013, 2132, 1990, 2018, 2018 };
    for (int i = 0; i < min(y1.size(),y2.size()); ++i) {
	int fr = year_diff_days(y1[i],y2[i]);
	int cr = year_diff_simple(y1[i],y2[i]);
	bool b = fr != cr;
	if (b)
	    cout << y1[i] << ' ' << y2[i] << ' '
		 << fr << ' ' << cr << '\n';
	r = r || b;
    }
    if (r)
	cout << "year_diff_days failed\n";
}

void minus_test()
{
    bool fail = false;
    vector<Date> d1{{2018, Month::jul, 04},
		    {2018, Month::jul, 04},
		    {2018, Month::jan, 01},
		    {1970, Month::jan, 01}};
    vector<Date> d2{{2018, Month::jul, 04},
		    {2018, Month::jul, 15},
		    {2018, Month::jul, 04},
		    {2018, Month::jul, 04}};
    vector<long> cr {0, 11,
		     days_since_ny(d2[2]),
		     1530709194L/86400L};
    for (int i = 0;
	 i < min({d1.size(), d2.size(), cr.size()});
	 ++i) {
	long y = d2[i] - d1[i];
	bool b = y != cr[i];
	if (b)
	    cout << d2[i] << '-' << d1[i] << " == "
		 << y << " | " << cr[i] << '\n';
	fail = fail || b;
    }
    if (fail)
	cout << "operator-(const Date&, const Date&) failed\n";
}

int days_until_ny_simple(const Date& dd)
{
    Date d1 = dd;
    Date d2 = {dd.year()+1, Month::jan, 1};
    int i = 0;
    while (d1 < d2)
	++d1, ++i;
    return i;
}

int days_since_ny_simple(const Date& dd)
{
    Date d1 {dd};
    Date d2 {dd.year(), Month::jan, 1};
    int i = 0;
    while (d2 < d1)
	++d2, ++i;
    return i;
}

void days_until_ny_test()
{
    bool fail = false;
    vector<Date> ta{ Date{2018, Month::dec, 30},
		     Date{2018, Month::dec, 20},
		     Date{2018, Month::jan, 1},
		     Date{2018, Month::nov, 30},
		     Date{2018, Month::jul, 04}};
    for (int i = 0; i < ta.size(); ++i) {
	int r = days_until_ny(ta[i]);
	int cr = days_until_ny_simple(ta[i]);
	bool b = r != cr;
	if (b)
	    cout << ta[i] << ' ' << r << ' ' << cr << '\n';
	fail = fail || b;
    }
    if (fail)
	cout << "days_until_ny failed\n";
}

void days_since_ny_test()
{
    bool fail = false;
    vector<Date> ta{ Date{2018, Month::dec, 30},
		     Date{2018, Month::dec, 20},
		     Date{2018, Month::jan, 1},
		     Date{2018, Month::nov, 30},
		     Date{2018, Month::jul, 04}};
    for (int i = 0; i < ta.size(); ++i) {
	int r = days_since_ny(ta[i]);
	int cr = days_since_ny_simple(ta[i]);
	bool b = r != cr;
	if (b)
	    cout << ta[i] << ' ' << r << ' ' << cr << '\n';
	fail = fail || b;
    }
    if (fail)
	cout << "days_since_ny failed\n";
}

void weekday_test()
{
    vector<Date> dv {
	{2013, Month::dec, 19},
	{1970, Month::may, 3},
	{2050, Month::mar, 7}
    };
    vector<Weekday> cr {
	Weekday::thu,
	Weekday::sat,
	Weekday::mon
    };
    bool fail = false;
    for (int i = 0; i<min(dv.size(), cr.size()); ++i) {
	Weekday r = weekday(dv[i]);
	bool b = r != cr[i];
	if (b)
	    cout << "weekday(" << dv[i] << ") == " << r << " | " << cr[i];
	fail = fail || b;
    }
    if (fail)
	cout << "weekday failed\n";
}

int main()
{
    // int y, m, d;
    // cin  >> y >> m >> d;
    // Date today {y, Month(m), d};
    // Date tomorrow = today;
    // tomorrow.add_day(1);
    // info("today", today);
    // info("tomorrow", tomorrow);

    year_diff_test();
    minus_test();
    days_since_ny_test();
    days_until_ny_test();
}
