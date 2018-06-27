#include "date.h"
#include "book.h"
using namespace Chrono;
int main()
{
     Date today { 1979, Month::jan, 2 };
     Book book { "C. Capy", "The art of capyness", "0-321-99278-4", today};
}
