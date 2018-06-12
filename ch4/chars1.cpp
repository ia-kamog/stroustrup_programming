// print table of lower case letters and their codes
#include "std_lib_facilities.h"
int main()
{
     constexpr int number_of_letters = 26;
     int i = 0;
     while (i < number_of_letters) {
	  cout << char('a'+i) << '\t' << 'a'+i << '\n';
	  ++i;
     }
}
