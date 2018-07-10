#ifndef ROMAN_H_
#define ROMAN_H_
#include <iostream>
struct Roman_int {
    int v;
};

std::istream& operator>>(std::istream&, Roman_int&);
std::ostream& operator<<(std::ostream&, Roman_int);
inline bool operator==(Roman_int x, Roman_int y)
{ return x.v == y.v; }
inline bool operator!=(Roman_int x, Roman_int y)
{ return x.v != y.v; }
inline bool operator<(Roman_int x, Roman_int y)
{ return x.v<y.v; }
inline bool operator<=(Roman_int x, Roman_int y)
{ return x.v<=y.v; }
inline bool operator>(Roman_int x, Roman_int y)
{ return x.v > y.v; }
inline bool operator>=(Roman_int x, Roman_int y)
{ return x.v >= y.v; }
inline Roman_int operator+(Roman_int x, Roman_int y)
{ return {x.v + y.v}; }
inline Roman_int operator-(Roman_int x, Roman_int y)
{ return {x.v - y.v}; }
inline Roman_int operator*(Roman_int x, Roman_int y)
{ return {x.v * y.v}; }
inline Roman_int operator/(Roman_int x, Roman_int y)
{ return {x.v / y.v}; }
inline Roman_int operator%(Roman_int x, Roman_int y)
{ return {x.v % y.v}; }
inline Roman_int operator+=(Roman_int& x, Roman_int y)
{ return {x.v += y.v}; }
inline Roman_int operator-=(Roman_int& x, Roman_int y)
{ return {x.v -= y.v}; }
inline Roman_int operator*=(Roman_int& x, Roman_int y)
{ return {x.v *= y.v}; }
inline Roman_int operator/=(Roman_int& x, Roman_int y)
{ return {x.v /= y.v}; }
inline Roman_int operator%=(Roman_int& x, Roman_int y)
{ return {x.v %= y.v}; }
inline Roman_int operator-(Roman_int x)
{ return {-x.v}; }

#endif
