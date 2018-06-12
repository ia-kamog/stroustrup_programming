// Exercise 6.9.
// Parse numbers.
#include "std_lib_facilities.h"

int read_int()
{
     bool neg = false;
     char c;
     int num = 0;
     cin >> c;
     if (!cin)
	  return 0;
     if (c == '-')
	  neg = true;
     if (!isdigit(c)) {
	  cin.putback(c);
	  error("Bad number!");
     } else
	  num = c - '0';
     while ((c=cin.get()) != EOF && isdigit(c))
	  num = 10*num + (c - '0');
     if (cin)
	  cin.putback(c);
     if (neg)
	  num = -num;
     return num;
}

int main()
{
     while (cin) {
	  int x = read_int();
	  cout << x << '\n';
     }
}
