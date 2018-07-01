#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
class Rational {
public:
     class Division_by_zero {};
     int denom() const { return d; }
     int numer() const { return n; }
     operator double() const { return (double)n/d; }
     Rational(int num, int den) :n{num},d{den}
	  { if (!d) throw Division_by_zero {}; }
private:
     int n;
     int d;
};
inline std::ostream& operator<<(std::ostream& os, const Rational& r)
{ return os << r.numer() << '/' << r.denom(); }
inline Rational operator+(const Rational& r1, const Rational& r2)
{ return {r1.numer()*r2.denom()+r1.denom()*r2.numer(),
	  r1.denom()*r2.denom()};}
inline Rational operator-(const Rational& r)
{ return {-r.numer(), r.denom()}; }
inline Rational operator-(const Rational& r1, const Rational& r2)
{ return r1 + (-r2); }
inline Rational  operator*(const Rational& r1, const Rational& r2)
{ return {r1.numer()*r2.numer(), r1.denom()*r2.denom()}; }
inline bool operator==(const Rational& r1, const Rational& r2)
{ return r1.denom()*r2.numer() == r1.numer()*r2.denom(); }
inline bool operator!= (const Rational& r1, const Rational& r2)
{ return !(r1 == r2); }
inline Rational operator/(const Rational& r1, const Rational& r2)
{
     if (r2 == 0) throw Rational::Division_by_zero{};
     return {r1.numer()*r2.denom(), r1.denom()*r2.numer()};
}
#endif
