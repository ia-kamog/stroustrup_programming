#include "book.h"
#include <array>
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

Book::Book(string a, string t, string i, Genre g, Date d)
     :author{a},title{t},date{d},genre{g},in{true}
{
     if (good_isbn(i))
	  isbn = i;
     else
	  throw Failure{};
}

bool operator==(const Book& b1, const Book& b2)
{
     auto isbn1 = b1.get_isbn();
     auto isbn2 = b2.get_isbn();
     bool eq = isbn1.size() == isbn2.size();
     for (size_t i = 0; eq && i < isbn1.size(); ++i)
	  eq = eq && tolower(isbn1[i])==tolower(isbn2[i]);
     return eq;
}

bool operator!=(const Book& b1, const Book& b2)
{
     return !(b1 == b2);
}

ostream& operator<<(ostream& os, Genre g)
{
     constexpr std::array<const char *, int(Genre::selfhelp)+1>
	  genre_names
	  { "Sci-fi", "Satire", "Drama",
	    "Adventure", "Romance", "Mystery",
	    "Horror", "Self-help" };
     return os << genre_names[int(g)];
}

ostream& operator<<(ostream& os, const Book& b)
{
     return os << "Author: " << b.get_author() << '\n'
	       << "Title: " << b.get_title() << '\n'
	       << "ISBN: " << b.get_isbn() << '\n'
	       << "Genre: " << b.get_genre() << '\n';
}
