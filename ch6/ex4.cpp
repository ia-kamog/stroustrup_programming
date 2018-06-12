// Exercise 6.4.
// Re-make of exercise 4.19 using classes.

#include "std_lib_facilities.h"
#include "ex4.h"

int main()
{
     const Name_score end("NoName", 0);
     vector<Name_score> values;
     
     for (Name_score x; cin>>x && x!=end;)
	  values.push_back(x);

     sort(values);

     for (size_t i=1; i<values.size(); ++i)
	  if (values[i-1].name == values[i].name)
	       error("Duplicate name discovered: "+values[i].name);

     for (const auto& x: values)
	  cout << x << '\n';
}
