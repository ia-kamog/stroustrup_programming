#include "string_util.h"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace S = String_util;
using Arg = const std::vector<std::string> &;
using Ind = std::size_t;
using std::invalid_argument;
using std::vector;

static inline Ind maxls(Arg v, Ind i1, Ind i2)
{
     return v[i1].size()>v[i2].size() ? i1 : i2;
}

static inline Ind minls(Arg v, Ind i1, Ind i2)
{
     return v[i1].size()<v[i2].size() ? i1 : i2;
}

static inline Ind maxs(Arg v, Ind i1, Ind i2)
{
     return v[i1]>v[i2] ? i1 : i2;
}

static inline Ind mins(Arg v, Ind i1, Ind i2)
{
     return v[i1]<v[i2] ? i1 : i2;
}

template <Ind (*f)(Arg v, Ind, Ind)> Ind reduce(Arg v)
{
     if (v.size() == 0)
	  throw invalid_argument("empty vector");
     Ind r = 0;
     for (Ind i = 0; i < v.size(); ++i)
	  r = f(v, r, i);
     return r;
}

vector<size_t> S::string_lengths(Arg v)
{
     vector<size_t> r(v.size());
     for (size_t i = 0; i < v.size(); ++i)
	  r[i] = v[i].size();
     return r;
}

Ind S::longest(Arg v) { return reduce<maxls>(v); }
Ind S::shortest(Arg v) { return reduce<minls>(v); }
Ind S::lex_first(Arg v) { return reduce<mins>(v); }
Ind S::lex_last(Arg v) { return reduce<maxs>(v); }

S::String_summary S::string_summary(Arg v)
{
     size_t sz = v.size();
     if (sz == 0)
	  throw invalid_argument("empty vector");
     S::String_summary r;
     r.shortest = r.longest = r.first = r.last = 0;
     r.lengths.resize(sz);
     for (Ind i = 0; i < sz; ++i) {
	  r.lengths[i] = v[i].size();
	  r.shortest = minls(v, r.shortest, i);
	  r.longest = maxls(v, r.longest, i);
	  r.first = mins(v, r.first, i);
	  r.last = maxs(v, r.last, i);
     }
     return r;
}
