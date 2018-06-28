#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

bool leapyyear(int y);

int main() try
{
     const vector<int> leapy { 2000, 2032, 1904, 1600, 1232 };
     const vector<int> not_leapy { 1700, 1246, 2001, 1999, 2002};
     for (int x: leapy)
	  if (!leapyyear(x))
	       throw runtime_error("function is not correct");
     for (int x: not_leapy)
	  if (leapyyear(x))
	       throw runtime_error("function is not correct");
     cout << "function is correct\n";
     return 0;
} catch (exception& e) {
     cerr << e.what() << endl;
     return 1;
}

bool leapyyear(int y)
{
     return y%4==0 && (y%400==0 || y%100!=0);
}
