#include "std_lib_facilities.h"

int main()
{
     int x = 2.9;
     char c = 1066;
     cout << "x = " << x << '\n'
	  << "c = " << c << ' ' << int(c) << '\n';
     // int x1 = narrow_cast<int>(2.9);
     // cout << "x1 = " << x1 << '\n';
     int x2 = narrow_cast<int>(2.0);
     cout << "x2 = " << x2 << '\n';
     // char c1 = narrow_cast<char>(1066);
     // cout << "c1 = " << int(c1) << '\n';
     char c2 = narrow_cast<char>(85);
     cout << "c2 = " << int(c2) << '\n';
}
