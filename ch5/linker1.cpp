#include "std_lib_facilities.h"
int area(int length, int width);
double area(double length, double width);
int main()
{
     int x = area(2,3);
}

double area(double length, double width)
{
     return length * width;
}
