#include "patron.h"
#include <iostream>
#include <string>
std::ostream& operator<<(std::ostream& os, const Patron& p)
{
     return os << "Name: " << p.get_name() << '\n'
	       << "Card Number: " << p.get_id() << '\n'
	       << "Fees: " << p.get_fees()
	       << (p.owes() ? " (owes)" : " (not owes)") << '\n';
}

bool operator==(const Patron& p1, const Patron& p2)
{
     return p1.get_id() == p2.get_id();
}

bool operator!=(const Patron& p1, const Patron& p2)
{
     return !(p1 == p2);
}
