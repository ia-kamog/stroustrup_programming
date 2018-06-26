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
     Month month() { return m; }
     int day() { return d; }
     int year() { return y; }
private:
     int y;
     Month m;
     int d;
};

std::ostream& operator<<(std::ostream&, Date&);
Month operator++(Month&);
#endif
