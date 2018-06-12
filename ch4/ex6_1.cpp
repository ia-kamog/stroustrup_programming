// Exercise 4.6.1: convert digit names to digits
#include "std_lib_facilities.h"

int main()
{
     const vector<string> digits = {"zero", "one", "two", "three",
			     "four", "five", "six", "seven",
			     "eight", "nine"};
     for (string input; cin >> input;) {
	  if (input.size() == 0)
	       continue;
	  else if (isalpha(input[0])) {
	       unsigned i;
	       for (i = 0; i < digits.size(); ++i)
		    if (input == digits[i])
			 break;
	       if (i == digits.size())
		    cout << "Unknown digit name!\n";
	       else
		    cout << i << '\n';
	  } else if (isdigit(input[0])) {
	       unsigned i = stoi(input);
	       if (0 <= i && i < digits.size())
		    cout << digits[i] << '\n';
	       else
		    cout << "Bad digit: " << i << '\n';
	  } else
	       cout << "Rogue input!\n";
     }
}
