// Exercise 3.9: convert word numerals "zero"..."four" into digits
#include "std_lib_facilities.h"
int main()
{
     cout << "Enter a word numeral\n";
     string str_num;
     cin >> str_num;
     int num;
     bool fail = false;
     if (str_num == "zero")
	  num = 0;
     else if (str_num == "one")
	  num = 1;
     else if (str_num == "two")
	  num = 2;
     else if (str_num == "three")
	  num = 3;
     else if (str_num == "four")
	  num = 4;
     else
	  fail = true;
     if (!fail)
	  cout << num << '\n';
     else
	  cout << "not a number I know\n";
}
