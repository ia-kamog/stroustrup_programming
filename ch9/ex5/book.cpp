#include "book.h"
#include <cctype>
#include <string>
using namespace std;
using namespace Chrono;

static bool good_isbn_part(const string& isbn, size_t& i)
{
     size_t j = i;
     while (j < isbn.size() && isdigit(isbn[j]))
	  ++j;
     if (i == j || j+1 >= isbn.size() || isbn[j] != '-') {
	  return false;
     } else {
	  i = j+1;
	  return true;
     }
}

void Book::check_in()
{
     if (in) throw Failure{};
     in = true;
}

void Book::check_out()
{
     if (!in) throw Failure{};
     in = false;
}

bool good_isbn(const string& isbn)
{
     size_t i = 0;
     return good_isbn_part(isbn, i) &&
	  good_isbn_part(isbn, i) &&
	  good_isbn_part(isbn, i) &&
	  isbn.size()-1 == i &&
	  isalnum(isbn[i]);
}

Book::Book(string a, string t, string i, Date d)
     :author{a},title{t},date{d},in{true}
{
     if (good_isbn(i))
	  isbn = i;
     else
	  throw Failure{};
}
