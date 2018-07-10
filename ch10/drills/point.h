#ifndef POINT_H_
#define POINT_H_
#include <iostream>
struct Point { int x, y; };
std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream&, Point&);
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);
#endif
