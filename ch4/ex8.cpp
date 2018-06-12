// Exercise 4.8: the story about doubling rice grains
#include "std_lib_facilities.h"

int main()
{
     vector<int> levels = {1000, 1000000, 1000000000};
     int cur_level = 0;
     int cur_square = 1;
     int rice_on_cur = 1;
     int total_rice = 0;
     while (cur_level < levels.size() && cur_square <= 64) {
	  total_rice += rice_on_cur;
	  if (total_rice >= levels[cur_level]) {
	       cout << "For the squares up to " << cur_square
		    << " is " << total_rice << " >= "
		    << levels[cur_level] << '\n';
	       ++cur_level;
	  }
	  rice_on_cur *= 2;
	  ++cur_square;
     }
}
