#ifndef DATE_H_
#define DATE_H_
#include <iostream>
enum class Month {
     jan = 1, feb, mar, apr, may, jun,
     jul, aug, sep, oct, nov, dec
};
class Date {
public:
     class Invalid_date {};
     Date(int y, Month m, int d);
     void add_day(int n);
     void add_month(int n);
     void add_year(int n);
     Month month() const { return m; }
     int day() const { return d; }
     int year() const { return y; }
private:
     int y;
     Month m;
     int d;
};

std::ostream& operator<<(std::ostream&, const Date&);
Month operator++(Month&);
#endif
