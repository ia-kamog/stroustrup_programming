#include "library.h"

#include "book.h"
#include "date.h"
#include "patron.h"

#include <string>
#include <vector>

using namespace std;
using namespace Chrono;
Library::Library() :bs{},ps{},ts{} { }

void Library::add_book(const Book& b)
{
     bs.push_back(b);
     bs.end()->check_in();
}

void Library::add_patron(const Patron& p)
{
     for (const auto& x: ps)
	  if (x == p)
	       throw Patron_dup{x.get_id()};
     ps.push_back(p);
}

void Library::check_out(const Patron& p, const Book& b, const Date& d)
{
     Patron *pp = nullptr;
     for (auto& x: ps)
	  if (x == p) {
	       pp = &x;
	       break;
	  }
     if (!pp) throw Patron_not_found{p};
     
     Book *bp = nullptr;
     for (auto& x: bs)
	  if (x == b) {
	       bp = &x;
	       break;
	  }
     if (!bp) throw Book_not_found{b};

     if (pp->owes()) throw Patron_owes{*pp};
     try { bp->check_out(); }
     catch (Book::Failure f) { throw Checked_out{*bp}; }
     pp->set_fees(pp->get_fees()+item_fee);

     ts.push_back(Transaction{*pp, *bp, d});
}

vector<string> Library::debtors() const
{
     vector<string> r;
     for (const auto& x: ps)
	  if (x.owes())
	       r.push_back(x.get_name());
     return r;
}
