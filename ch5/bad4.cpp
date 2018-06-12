#include "std_lib_facilities.h"

constexpr int frame_width = 2;

int f(int, int, int);
int area(int, int);
int framed_area(int, int);

int main()
{
     int x, y, z;
     cin >> x >> y >> z;
     int r = f(x,y,z);
     cout << "f returns " << r << '\n';
}

int f(int x, int y, int z)
{
     int area1 = area(x,y);
     if (area1 <= 0) error("non-positive area");
     int area2 = framed_area(1,z);
     if (area2 <= 0) error("non-positive area");
     int area3 = framed_area(y,z);
     if (area3 <= 0) error("non-positive area");
     double ratio = double(area1)/area3;
     cout << area1 << '\t' << area2 << '\t'
	  << area3 << '\t' << ratio << '\n';
     return 0;
}

int area(int length, int width)
{
     if (length <= 0 || width <= 0) return -1;
     return length*width;
}

int framed_area(int x, int y)
{
     return area(x-frame_width, y-frame_width);
}
