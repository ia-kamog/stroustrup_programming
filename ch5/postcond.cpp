#include "std_lib_facilities.h"

int area(int length, int width)
{
     if (length <= 0 || width <= 0) error("area pre-condition");
     int a = length*width;
     if (a <= 0) error("area post-condition");
     return a;
}

int main()
{
     int a = 1 << 30;
     int b = 2;
     cout << area(a,b) << '\n';
     return 0;
}
