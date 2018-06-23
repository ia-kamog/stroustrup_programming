/* Exercise 8.12
   print_until_s and print_util_ss */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_until_s(const vector<string>& v, string quit)
{
     for (auto x : v) {
	  if (x == quit) return;
	  cout << x << '\n';
     }
}

void print_until_ss(const vector<string>& v, string quit)
{
     constexpr unsigned max_times = 2;
     unsigned times = 0;
     for (auto x : v) {
	  if (x==quit && ++times==max_times)
	       return;
	  cout << x << '\n';
     }
}

int main()
{
     string quit;
     cin >> quit;
     vector<string> v;
     for (string s; cin >> s;)
	  v.push_back(s);
     
     print_until_s(v, quit);
     cout << "=========\n";
     print_until_ss(v, quit);
}
