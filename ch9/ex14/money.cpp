#include "money.h"

#include <cmath>
#include <iostream>

using namespace std;

Money::Money(double d)
{
    tc = d < 0 ? -lround(100*-d) : lround(100*d);
}

Money::Money(int d, int c)
{
    tc = 100L*d + c;
}

Money operator+(const Money& m1, const Money& m2)
{
    return { m1.total_cents() + m2.total_cents() };
}
Money operator-(const Money& m1 , const Money& m2)
{
    return { m1.total_cents() - m2.total_cents() };
}
Money operator*(double x, const Money& m)
{
    return { x * m.total_cents() };
}

Money operator/(const Money& m, double x)
{
    return { m.total_cents()/x };
}


bool operator<(const Money& a, const Money& b)
{
    return a.total_cents() < b.total_cents();
}
bool operator>(const Money& a, const Money& b)
{
    return a.total_cents() > b.total_cents();
}
bool operator==(const Money& a, const Money& b)
{
    return a.total_cents() == b.total_cents();
}
bool operator!=(const Money& a, const Money& b)
{
    return a.total_cents() != b.total_cents();
}
bool operator<=(const Money& a, const Money& b)
{
    return a.total_cents() <= b.total_cents();
}
bool operator>=(const Money& a, const Money& b)
{
    return a.total_cents() >= b.total_cents();
}

istream& operator>>(istream& is, Money& m)
{
    char ds;
    double x;
    is >> ds >> x;
    if (!is)
	return is;
    if (ds != '$') {
	is.setstate(ios::failbit);
	return is;
    }
    m = Money{x};
}

ostream& operator<<(ostream& os, const Money& m)
{
    int d = m.dollars();
    int c = abs(m.cents());
    return os << '$' << d << '.' << (c < 10 ? "0" : "") << c;
}
