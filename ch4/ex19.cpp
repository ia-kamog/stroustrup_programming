// Exercise 4.19: check scores with names for uniqueness and print
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

     for (int i = 0; i < scores.size(); ++i)
	  cout << names[i] << '\t' << scores[i] << '\n';
}
