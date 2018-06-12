#include "std_lib_facilities.h"

int main()
     try {
	  if (true) {
	       cout << "Success!\n";
	  } else {
	       cout << "Fail!\n";
	  }
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
