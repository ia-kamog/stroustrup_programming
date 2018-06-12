#include "std_lib_facilities.h"
double some_function()
{
     double d = 0;
     cin >> d;
     if (!cin) error("couldn't read a double in 'some_function()'");
     return d;
}

int main() {
     double x = some_function();
     cout << x << '\n';
}
