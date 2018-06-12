// Exercise 4.20: check scores with names for uniqueness and query
#include "std_lib_facilities.h"
int main()
{
     string name;
     vector<string> names;
     int score;
     vector<int> scores;

     while (cin >> name >> score) {
	  if (name == "NoName" && score == 0)
	       break;
	  for (const string& x: names)
	       if (name == x)
		    simple_error("Duplicate name");
	  names.push_back(name);
	  scores.push_back(score);
     }
     cout << "Enter names to query\n";
     while (cin >> name) {
	  int i;
	  for (i = 0; i < names.size(); ++i)
	       if (name == names[i])
		    break;
	  if (i == names.size())
	       cout << "name not found\n";
	  else
	       cout << scores[i] << '\n';
     }
}
