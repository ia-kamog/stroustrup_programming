#include "std_lib_facilities.h"

int main()
     try {
	  int x = 20;
	  char c = x;
	  if (c == x)
	       cout << "Success!\n";		    
	  return 0;
     }
     catch (exception& e) {
	  cerr << "error: " << e.what() << '\n';
	  return 1;
     }
     catch (...) {
	  cerr << "Unknown exception!\n";
	  return 2;
     }
