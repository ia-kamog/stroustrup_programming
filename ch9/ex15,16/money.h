#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>
#include <vector>


enum Currency {
    USD, GBP, RUB, EUR, DKK
};

class Money {
public:
    static std::vector<double> conversion_table;
    Money() :tc {0}, cur{Currency::USD} {}
    Money(Currency, long cents) :tc{cents} {};
    Money(Currency, int dollars, int cents);
    Money(Currency, double dollars);
    int whole_units() const { return tc/100; }
    operator double() const { return tc/100.0; }
    int small_units() const { return (tc < 0)? -(-tc%100) : tc % 100; }
    long total_units() const { return tc; }
    Money convert(Currency c) const;
    Currency currency() const { return cur; }
private:
    Currency cur;
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
std::istream& operator>>(std::istream& is, Currency&);
std::ostream& operator<<(std::ostream& os, Currency);

#endif
