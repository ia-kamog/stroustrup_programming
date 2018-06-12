// exercise 3.2: convert miles to kilometers
#include "std_lib_facilities.h"

int main()
{
     cout << "Enter a distance in miles\n";
     double miles {0.0};
     cin >> miles;
     double kilometers = 1.609 * miles;
     cout << miles << " mi = " << kilometers << " km\n";
}
