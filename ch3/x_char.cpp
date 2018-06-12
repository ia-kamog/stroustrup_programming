// print the character code of 'x'
#include "std_lib_facilities.h"

int main()
{
     char c = 'x';
     int i1 = c;
     int i2 = 'x';
     char c2 = i1;
     cout << "Character " << c << " has the code = " << i1
	  << " ('" << c2 << "' = " << i2 << ")\n";
}
