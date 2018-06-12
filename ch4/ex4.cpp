// Exercise 4.4: guessing game for numbers between 1 and 100
#include "std_lib_facilities.h"

int main()
{
     int start = 1;
     int end = 100;
     cout << "Think of a number between " << start << " and "
	  << end << ".\n";

     while (start != end) {
	  int middle = (start+end)/2;
	  cout << "Is it less than " << middle << "? (y or n)\n";
	  char response;
	  cin >> response;
	  if (response == 'y')
	       end = middle-1;
	  else
	       start = middle;
     }
     cout << "I'm sure the number is " << start << ".\n";
}
