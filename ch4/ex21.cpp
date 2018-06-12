// Exercise 4.21: check scores with names for uniqueness and query scores
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
     cout << "Enter scores to query\n";
     while (cin >> score) {
	  int i;
	  bool found = false;
	  for (i = 0; i < scores.size(); ++i)
	       if (score == scores[i]) {
		    found = true;
		    cout << names[i] << '\n';
	       }
	  if (!found)
	       cout << "score not found\n";
     }
}
