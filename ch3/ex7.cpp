// Exercise 3.6: order three string values
#include "std_lib_facilities.h"

int main()
{
     cout << "Enter three strings\n";
     string s1, s2, s3;
     cin >> s1 >> s2 >> s3;
     if (s1 > s2)
	  swap(s1, s2);
     // s1 <= s2
     if (s2 > s3)
	  swap(s2, s3);
     // s1 <= s3, s2 <= s3
     if (s1 > s2)
	  swap(s1, s2);
     // s1 <= s2, s2 <= s3
     string sep = ", ";
     cout << s1 << sep << s2 << sep << s3 << '\n';
}
     
