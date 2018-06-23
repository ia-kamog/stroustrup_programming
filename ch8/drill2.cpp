#include <iostream>
using namespace std;

void swap_v(int a, int b)
{ int temp; temp=a, a=b, b=temp; }
void swap_r(int& a, int& b)
{ int temp; temp=a, a=b, b=temp; }
// void swap_cr(const int& a, const int& b)
// { int temp; temp=a, a=b, b=temp; }

int main()
{
     const int cx = 7, cy = 9;
     double dx, dy;
     int x, y;
     
     x = 7, y = 9;
     dx = 7.7, dy = 9.9;
     swap_v(x,y);
     swap_v(7,9);
     swap_v(cx, cy);
     swap_v(dx, dy);
     swap_v(7.7, 9.9);
     cout << x << ' ' << y << ' ' << cx << ' ' << cy
	  << dx << ' ' << dy << '\n';
     x = 7, y = 9;
     dx = 7.7, dy = 9.9;
     swap_r(x,y);
     // swap_r(7,9);
     // swap_r(cx, cy);
     // swap_r(dx, dy);
     // swap_r(7.7, 9.9);
     cout << x << ' ' << y << ' ' << cx << ' ' << cy
	  << dx << ' ' << dy << '\n';
     x = 7, y = 9;
     dx = 7.7, dy = 9.9;
     // swap_cr(x,y);
     // swap_cr(7,9);
     // swap_cr(cx, cy);
     // swap_cr(dx, dy);
     // swap_cr(7.7, 9.9);
     cout << x << ' ' << y << ' ' << cx << ' ' << cy
	  << dx << ' ' << dy << '\n';
}
