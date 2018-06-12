// Exercise 5.14;
// Read days of the week with number and sum them
#include "std_lib_facilities.h"

constexpr int days_in_week = 7;
const vector<string> short_names =
{ "mon", "tue", "wed", "thu", "fri", "sat", "sun"};
const vector<string> long_names =
{ "monday", "tuesday", "wednesday", "thursday",
  "friday", "saturday", "sunday" };

int match_weekday(string& s)
{
     for (char& x: s)
	  x = tolower(x);
     for (size_t i = 0; i < days_in_week; ++i)
	  if (s == long_names[i] || s == short_names[i])
	       return i;
     return -1;
}

int main()
{
     vector<vector<int>> weeks(days_in_week);
     string week;
     int num;
     int bad = 0;
     while (cin >> week >> num) {
	  int x = match_weekday(week);
	  if (x == -1) {
	       ++bad;
	       continue;
	  }
	  weeks[x].push_back(num);
     }

     vector<int> sums(days_in_week);
     for (size_t i = 0; i < sums.size(); ++i)
	  for (int x: weeks[i])
	       sums[i] += x;

     for (size_t i=0; i<sums.size(); ++i)
	  cout << short_names[i] << '\t' << sums[i] << '\n';
     cout << "bad\t" << bad << '\n';
}
