// print table of latin letters and digits and their codes
#include "std_lib_facilities.h"
int main()
{
     char ch;
     for (ch = '0'; ch <= '9'; ++ch)
	  cout << ch << '\t' << int{ch} << '\n';
     for (ch = 'a'; ch <= 'z'; ++ch)
	  cout << ch << '\t' << int{ch} << '\n';
     for (ch = 'A'; ch <= 'Z'; ++ch)
	  cout << ch << '\t' << int{ch} << '\n';
}
