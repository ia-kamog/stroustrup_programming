#ifndef DATE_H_
#define DATE_H_
#include <iostream>
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
std::ostream& operator<<(std::ostream&, Weekday);
Month operator++(Month&);
int operator-(Date d1, Date d2);
bool operator<(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
Date next_workday(const Date& d);
int week_of_year(const Date& d);
Weekday weekday(const Date& d); 
#endif
