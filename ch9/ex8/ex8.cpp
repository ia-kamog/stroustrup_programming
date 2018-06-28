#include "date.h"
#include "book.h"
#include <iostream>
using namespace Chrono;
using namespace std;
int main()
{
     Date today { 1979, Month::jan, 2 };
     Book book { "C. Capy", "The art of capyness",
		 "0-321-99278-4", Genre::selfhelp,
		 today };
     cout << book;
     Patron pat { "Welby Wallaby", 23 };
     pat.set_fees(-10.2);
     cout << pat;
}
