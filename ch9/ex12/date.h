#ifndef DATE_H_
#define DATE_H_
#include <iostream>
namespace Chrono {
    enum class Month {
	jan = 1, feb, mar, apr, may, jun,
	jul, aug, sep, oct, nov, dec
    };

    enum class Weekday {
	mon, tue, wed, thu, fri, sat, sun
    };

    class Date {
    public:
	class Invalid_date {};
	Date(int y, Month m, int d);
	void add_day(long n);
	void add_month(int n);
	void add_year(int n);
	Month month() const { int y,d; Month m; date(y,m,d); return m; } 
	int day() const { int y,d; Month m; date(y,m,d); return d; } 
	int year() const { int y,d; Month m; date(y,m,d); return y; } 
	Date& operator++();
	long int days_since() const {return days;}
    private:
	void date(int& y, Month& m, int& d) const;
	void add_within_year(int n);
	long int days;
	
    };

    constexpr Weekday first_day_of_week = Weekday::mon;
    constexpr double average_year = 365.2425;
    Date first_day_of_year(const Date&);
    // count days since and until the new year
    int days_since_ny(const Date& d);
    int days_until_ny(const Date& d);
    // number leap days between the first day of year y1
    // and the first day of year y2
    int leap_days_count(int y1, int y2);

    inline bool leap_year(int y) { return y%4==0 && (y%400==0 || y%100!=0); }

    int month_length(int y, Month);
    int month_length(const Date& d); // length of the current month

    bool valid_date(int y, Month m, int d);
    // number of days in [01-01-y1; 01-01-y2)
    long year_diff_days(int y1, int y2);
 
    std::ostream& operator<<(std::ostream&, const Date&);
    std::istream& operator>>(std::istream&, Date&);
    std::ostream& operator<<(std::ostream&, Weekday);

    inline Month operator++(Month& m)
    {
	return m = (m==Month::dec)? Month::jan : Month(int(m)+1);
    }
    inline Month operator--(Month& m)
    {
	return m = (m!=Month::jan) ? Month(int(m)-1) : Month::dec;
    }
    // number of days in [d1; d2)
    long operator-(const Date& d1, const Date& d2);

    bool operator<(const Date& d1, const Date& d2);

    bool operator==(const Date& d1, const Date& d2);

    bool operator!=(const Date& d1, const Date& d2);

    Date next_workday(const Date& d);

    int week_of_year(const Date& d);

    Weekday weekday(const Date& d);
}
#endif
