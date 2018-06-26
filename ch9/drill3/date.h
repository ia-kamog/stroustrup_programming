#ifndef DATE_H_
#define DATE_H_
#include <iostream>
class Date {
     int d, m, y;
public:
     class Invalid_date {};
     Date(int y, int m, int d);
     void add_day(int n);
     int month() { return m; }
     int day() { return d; }
     int year() { return y; }
};

std::ostream& operator<<(std::ostream&, Date&);
#endif
