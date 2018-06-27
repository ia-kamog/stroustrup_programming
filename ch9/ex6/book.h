#ifndef BOOK_H_
#define BOOK_H_
#include "date.h"
#include <iostream>
#include <string>
class Book {
public:
     class Failure { };
     const std::string& get_isbn() const { return isbn; }
     const std::string& get_author() const { return author; }
     const std::string& get_title() const { return title; }
     const Chrono::Date& get_date() const { return date; }
     Book(std::string author, std::string title,
	  std::string isbn, Chrono::Date date);
     void check_in();
     void check_out();
private:
     std::string isbn;
     std::string author;
     std::string title;
     Chrono::Date date;
     bool in;
};

bool good_isbn(const std::string& isbn);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
std::ostream& operator<<(std::ostream&, const Book&);
#endif
