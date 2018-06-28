#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "book.h"
#include "date.h"
#include "patron.h"

#include <string>
#include <vector>

class Library {
public:
     static constexpr double item_fee = 0.15;
     struct Checked_out { Book b; };
     struct Patron_dup { int id; };
     struct Patron_not_found { Patron p; };
     struct Book_not_found { Book b; };
     struct Patron_owes { Patron p; };
     Library();
     void add_book(const Book& b);
     void add_patron(const Patron& p);
     void check_out(const Patron& pat, const Book& b, const Chrono::Date&);
     std::vector<std::string> debtors() const;
private:
     struct Transaction {
	  Patron p;
	  Book b;
	  Chrono::Date d;
     };
     std::vector<Book> bs;
     std::vector<Patron> ps;
     std::vector<Transaction> ts;
};
#endif
