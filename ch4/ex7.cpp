// Exercise 4.7: calculator with word or digit input (0-9)
#include "std_lib_facilities.h"

int string_to_digit(string);

int main()
{
     string as, bs;
     char op;
     
     while (cin >> as >> bs >> op) {
	  string result_name;
	  int result;
	  int a = string_to_digit(as);
	  if (a == -1)
	       continue;
	  int b = string_to_digit(bs);
	  if (b == -1)
	       continue;
	  switch (op) {
	  case '+':
	       result_name = "sum of";
	       result = a + b;
	       break;
	  case '-':
	       result_name = "difference between";
	       result = a - b;
	       break;
	  case '*':
	       result_name = "product of";
	       result = a*b;
	       break;
	  case '/':
	       result_name = "ratio of";
	       result = a / b;
	       break;
	  default:
	       simple_error("Unknown operation!");
	  }
	  cout << "The " << result_name << ' ' << a << " and " << b
	       << " is " << result << ".\n";
     }
}

int string_to_digit(string input)
{
     const vector<string> digits = {"zero", "one", "two", "three",
				    "four", "five", "six", "seven",
				    "eight", "nine"};
     if (input.size() == 0) {
	  cout << "No input?\n";
	  return -1;
     } else if (isalpha(input[0])) {
	  unsigned i;
	  for (i = 0; i < digits.size(); ++i)
	       if (input == digits[i])
		    break;
	  if (i == digits.size()) {
	       cout << "Unknown digit name!\n";
	       return -1;
	  } else {
	       return i;
	  }
     } else if (isdigit(input[0])) {
	  return stoi(input);
     } else {
	  cout << "Rogue input\n";
	  return -1;
     }
}	  
