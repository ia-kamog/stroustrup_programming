#include "roman.h"
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
vector<Roman_int> values {{0},{1},{5},{10},{50},{100},{500},{1000}};
vector<char> symbols {'N', 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
ostream& operator<<(ostream& os, Roman_int r)
{
    if (r.v == 0)
	return os << 'N';
    if (r.v < 0) {
	os << '-';
	r = -r;
    }
    while (r >= values[values.size()-1]) {
	r -= values[values.size()-1];
	os << symbols[symbols.size()-1];
    }
    for (int i = values.size()-2; r != Roman_int{0} && i > 0; --i) {
	if ((r - values[i])/values[i] > (values[i+1] - r)/values[i]) {
	    while (r < values[i+1]) {
		r += values[i];
		os << symbols[i];
	    }
	    r -= values[i+1];
	    os << symbols[i+1];
	} else {
	    while (r >= values[i]) {
		r -= values[i];
		os << symbols[i];
	    }
	}
    }
    return os;
}

int sym_int(char s)
{
    for (int i = 0; i < symbols.size(); ++i)
	if (symbols[i] == s)
	    return i;
    return -1;
}

istream& operator>>(istream& is, Roman_int& r)
{
    int res = 0, sign = 1;
    char s;
    is >> s;
    if (!is)
	return is;
    if (s == '-')
	sign = -1;
    else
	is.unget();
    int level = values.size();
    int acc = 0;
    int cl = -1;
    while (is) {
	bool quit = false;
	cl = -1;
	quit = !(is>>s) || ((cl=sym_int(s)) == -1) || cl == 0;
	if (cl == level)
	    acc += values[cl].v;
	else if (cl == level+1) {
	    res += values[level+1].v - acc;
	    acc = 0;
	    level--;
	} else if (0 <= cl && cl < level) {
	    res += acc;
	    acc = values[cl].v;
	    level = cl;
	}
	if (quit) break;
    }
    res += acc;
    if (is && cl == -1)
	is.unget();
    if (is.fail()) {
	is.clear();
	is.unget();
	is.clear(ios_base::failbit);
    }
    r.v = sign*res;
    return is;
}
