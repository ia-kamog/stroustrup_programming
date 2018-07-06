#ifndef UTIL_H_
#define UTIL_H_
namespace Util {
	inline constexpr long ceil(long a, long q)
	{ return a/q + bool(a%q); }
	inline constexpr long mod_count(long q, long a, long b)
	{ return ceil(b,q) - ceil(a,q); }
}
#endif	
