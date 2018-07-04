#include "money.h"

#include <cctype>
#include <cmath>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<double> Money::conversion_table
{ 1.0, 0.75, 63.27, 0.86, 6.38 };

static const vector<string> curnames {
    "USD", "GBP", "RUB", "EUR", "DKK"
};

Money::Money(Currency c, double d)
    :cur{c}
{
    tc = d < 0 ? -lround(100*-d) : lround(100*d);
}

Money::Money(Currency c, int d, int s)
    :cur{c}
{
    tc = 100L*d + s;
}

Money operator+(const Money& m1, const Money& m2)
{
    if (m1.currency() == m2.currency())
	return { m1.currency(), m1.total_units() + m2.total_units() };
    else
	return m1 + m2.convert(m1.currency());
}
Money operator-(const Money& m1 , const Money& m2)
{
    if (m1.currency() == m2.currency())
	return { m1.currency(), m1.total_units() - m2.total_units() };
    else
	return m1 - m2.convert(m1.currency());
}
Money operator*(double x, const Money& m)
{
    return { m.currency(), x * m.total_units() };
}

Money operator/(const Money& m, double x)
{
    return { m.currency(), m.total_units()/x };
}

bool operator<(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() < b.total_units();
    else
	return a < b.convert(a.currency());
}
bool operator>(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() > b.total_units();
    else
	return a > b.convert(a.currency());
}
bool operator==(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() == b.total_units();
    else
	return a == b.convert(a.currency());
}
bool operator!=(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() != b.total_units();
    else
	return a != b.convert(a.currency());
}
bool operator<=(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() <= b.total_units();
    else
	return a <= b.convert(a.currency());
}
bool operator>=(const Money& a, const Money& b)
{
    if (a.currency() == b.currency())
	return a.total_units() >= b.total_units();
    else
	return a>=b.convert(a.currency());
}

istream& operator>>(istream& is, Money& m)
{
    Currency c;
    double x;
    is >> c >> x;
    if (!is)
	return is;
    m = Money{c,x};
}

ostream& operator<<(ostream& os, const Money& m)
{
    int d = m.whole_units();
    int c = abs(m.small_units());
    return os << m.currency() << d << '.' << (c < 10 ? "0" : "") << c;
}

std::ostream& operator<<(std::ostream& os, Currency c)
{
    return os << curnames.at(int(c));
}

std::istream& operator>>(std::istream& is, Currency& c)
{
    while (is && isspace(is.get()))
	;
    if (!is)
	return is;
    else
	is.unget();
    string cn;
    for (int i = 0; is && i < 3; ++i)
	cn += toupper(is.get());
    if (!is)
	return is;
    int ind;
    for (ind = 0; ind < curnames.size(); ++ind)
	if (curnames[ind] == cn)
	    break;
    if (ind == curnames.size())
	is.setstate(ios::failbit);
    else 
	c = Currency(ind);
    return is;
}

Money Money::convert(Currency nc) const
{
    if (nc == cur)
	return Money{*this};
    long v = total_units();
    double neg = v < 0 ? -1 : 1;
    return Money{nc, neg * v /
	    conversion_table[currency()]* conversion_table[nc]};
}
