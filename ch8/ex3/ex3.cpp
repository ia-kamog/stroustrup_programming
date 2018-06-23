/* Exercise 8.3
   Print sequence of Fibonacci numbers with give initial value
   and the number of elements to print. */
#include <vector>
#include <iostream>
#include "fib.h"
#include "print.h"

using namespace std;

int main()
{
     cout << "Print a Fibonacci sequence.\n";
     cout << "Enter the first element:\n";
     int x;
     cin >> x;
     cout << "Enter the second element:\n";
     int y;
     cin >> y;
     cout << "Enter the length of the sequence:\n";
     unsigned n;
     cin >> n;

     vector<int> v;
     fibonacci(x, y, v, n);

     print("fib", v);
}
