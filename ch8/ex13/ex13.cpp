#include "string_util.h"
#include "print.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace S = String_util;

static vector<string> read_strings();

int main()
{
     vector<string> v = read_strings();
     if (v.size() == 0) {
	  print("lengths =", S::string_lengths(v));
	  return 0;
     }
     S::String_summary s = S::string_summary(v);
     cout << "String_summary {\n";
     print("\tlengths =", s.lengths);
     cout << "\tfirst = " << s.first
	  << "\n\tlast = "<< s.last
	  << "\n\tshortest = " << s.shortest
	  << "\n\tlongest = " << s.longest
	  << "\n}\n";
     print("lengths = ", S::string_lengths(v));
     cout << "lex_first = " << S::lex_first(v)
	  << "\nlex_last = " << S::lex_last(v)
	  << "\nshortest = " << S::shortest(v)
	  << "\nlongest = " << S::longest(v) << '\n';
}

vector<string> read_strings()
{
     vector<string> r;
     for (string s; cin >> s; )
	  r.push_back(s);
     return r;
}
