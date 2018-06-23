#include "../std_lib_facilities.h"

string program_name = "silly";
vector<string> v;

void f()
{
     string s;
     while (cin>>s && s!="quit") {
	  string stripped;
	  string not_letters;
	  for (size_t i=0; i<s.size(); ++i)
	       if (isalpha(s[i]))
		    stripped += s[i];
	       else
		    not_letters += s[i];
	  v.push_back(stripped);
     }
}
