// Exercise 4.5: simple calculator
#include "std_lib_facilities.h"

int main()
{
     double a = 0;
     double b = 0;
     char op = ' ';

     cin >> a >> b >> op;
     string result_name;
     double result;
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
