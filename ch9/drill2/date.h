#ifndef DATE_H_
#define DATE_H_
#include <iostream>
struct Date {
     class Invalid_date {};
     int d, m, y;
     Date(int y, int m, int d);
     void add_day(int n);
};

std::ostream& operator<<(std::ostream&, const Date&);
#endif
