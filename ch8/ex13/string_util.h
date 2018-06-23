#ifndef STRING_UTIL_H_
#define STRING_UTIL_H_
#include <vector>
#include <string>
namespace String_util {
     std::vector<size_t> string_lengths(const std::vector<std::string>&);
     std::size_t longest(const std::vector<std::string>&);
     std::size_t shortest(const std::vector<std::string>&);
     std::size_t lex_first(const std::vector<std::string>&);
     std::size_t lex_last(const std::vector<std::string>&);

     struct String_summary {
	  std::vector<size_t> lengths;
	  std::size_t shortest, longest, first, last;
     };
     String_summary string_summary(const std::vector<std::string>&);
}
#endif
