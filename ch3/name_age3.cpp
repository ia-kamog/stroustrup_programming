// ask name and age and greet with age in months
#include "std_lib_facilities.h"

int main()
{
     cout << "Please enter your first name and age\n";
     string name;
     double age;
     cin >> name >> age;
     cout << "Hello, " << name << " (age " << 12.0*age << " months)\n";
}
