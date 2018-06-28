#include "book.h"
#include "date.h"
#include "library.h"
#include "patron.h"
#include <iostream>
using namespace Chrono;
using namespace std;
int main() try
{
     Date today { 1979, Month::jan, 2 };
     Book book { "C. Capy", "The art of capyness",
		 "0-321-99278-4", Genre::selfhelp,
		 today };
     cout << book;
     Patron pat { "Welby Wallaby", 23 };
     pat.set_fees(0);
     cout << pat;
     Library lib;
     lib.add_book(book);
     lib.add_patron(pat);
     lib.check_out(pat, book, today);
//   lib.check_out(pat, book, today);
     for (auto& x: lib.debtors())
	  cout << x;
     cout << '\n';
}
catch (Library::Patron_owes& e) {
     cout << "Patron already owes money:\n" << e.p;
     return 1;
}
catch (Library::Patron_not_found& e) {
     cout << "Not found patron:\n" << e.p;
     return 2;
}
catch (Library::Book_not_found& e) {
     cout << "Not found book:\n" << e.b;
     return 3;
}
catch (Library::Checked_out& e) {
     cout << "The book already checked out:\n" << e.b;
}
