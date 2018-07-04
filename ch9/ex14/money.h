#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>

class Money {
public:
    Money() :tc {0} {}
    Money(long cents) :tc{cents} {};
    Money(int dollars, int cents);
    Money(double dollars);
    int dollars() const { return tc/100; }
    operator double() const { return tc/100.0; }
    int cents() const { return (tc < 0)? -(-tc%100) : tc % 100; }
    long total_cents() const { return tc; }
private:
    long int tc; // total cents
};

Money operator+(const Money&, const Money&);
Money operator-(const Money&, const Money&);
Money operator*(double x, const Money&);
Money operator/(const Money&, double x);
bool operator<(const Money&, const Money&);
bool operator>(const Money&, const Money&);
bool operator==(const Money&, const Money&);
bool operator!=(const Money&, const Money&);
bool operator<=(const Money&, const Money&);
bool operator>=(const Money&, const Money&);
std::istream& operator>>(std::istream& is, Money&);
std::ostream& operator<<(std::ostream& os, const Money&);

#endif
