#include "point.h"
#include <ios>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
    char ch1;
    is >> ch1;
    if (!is)
	return is;
    if (ch1 != '(') {
	is.unget();
	is.clear(ios_base::failbit);
	return is;
    }
    int x, y;
    char ch2, ch3;
    is >> x >> ch2 >> y >> ch3;
    if (!is || ch2 != ',' || ch3 != ')') {
	is.clear(ios_base::badbit);
	return is;
    }

    p = Point{x,y};
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}
