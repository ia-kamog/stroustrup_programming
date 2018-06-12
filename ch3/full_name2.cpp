// read first and second name
#include "std_lib_facilities.h"

int main()
{
     cout << "Please enter your first and second names\n";
     string first;
     string second;
     cin >> first >> second;
     string name = first + ' ' + second;
     cout << "Hello, " << name << '\n';
}
