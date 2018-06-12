// Exercise 3.10: calculate one arithmetic operation with two argument
// Operations: +, -, *, /, plus, minus, mul, div
#include "std_lib_facilities.h"
int main()
{
     string operation;
     double arg1, arg2, result;

     cin >> operation >> arg1 >> arg2;

     if (operation == "+" || operation == "plus")
	  result = arg1 + arg2;
     else if (operation == "-" || operation == "minus")
	  result = arg1 - arg2;
     else if (operation == "*" || operation == "mult")
	  result = arg1 * arg2;
     else if (operation == "/" || operation == "div") {
	  if (arg1 == 0.0)
	       simple_error("Division by zero!");
	  else
	       result = arg1 / arg2;
     } else
	  simple_error("Unknown operation!");

     cout << result << '\n';
}
