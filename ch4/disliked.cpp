// bleep disliked words copying standard input to output
#include "std_lib_facilities.h"

int main()
{
     const string bleep = "BLEEP";
     const vector<string> disliked = {"Broccoli", "Putin"};

     for (string word; cin >> word;) {
	  bool found = false;
	  for (const string& x : disliked)
	       if (x == word)
		    found = true;
	  if (found)
	       cout << bleep;
	  else
	       cout << word;
	  cout << '\n';
     }
}
