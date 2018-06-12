// Exercise 6.10
// Calculate permutation or a combination of two numbers
#include "std_lib_facilities.h"

long perm(int, int);
long comb(int, int);

int main() try
{
     cout << "How many elements in the set?\n";
     int n;
     cin >> n;
     cout << "How many elements will be taken out?\n";
     int m;
     cin >> m;
     cout << "Do you want the permutation (P) or the combination (C) function?\n";
     char ch;
     cin >> ch;
     ch = toupper(ch);
     switch (ch) {
     case 'C':
	  cout << "C(" << n << "," << m << ") = " << comb(n, m) << '\n';
	  break;
     case 'P':
	  cout << "P(" << n << "," << m << ") = " << perm(n, m) << '\n';
	  break;
     default:
	  cerr << "Bad function: " << ch << '\n';
	  return 1;
     }
     return 0;
}
catch (exception& e)
{
     cerr << e.what() << '\n';
     return 2;
}

long perm(int n, int m)
{
     if (n < 0 || m < 0 || n < m)
	  error("bad arguments for permutation function");
     long p = 1;
     for (int i = n-m+1; i <= n; ++i)
	  p *= i;
     return p;
}

long comb(int n, int m)
{
     if (n < 0 || m < 0 || n < m)
	  error("bad argumuments for combination function");
     long p = perm(n, m);
     for (int i = 1; i <= m; ++i)
	  p /= i;
     return p;
}
