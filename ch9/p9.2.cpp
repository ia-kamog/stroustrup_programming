#include <iostream>
class X {
public:
     int m;
     int mf(int v) { int old = m; m = v; return old; }
};

int main()
{
     X var;
     var.m = 7;
     std::cout << var.m << '\n';
     int x = var.mf(9);
     std::cout << x << ' ' << var.m << '\n';
}
