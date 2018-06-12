// Exercisr 4.3: summarize distances between cities
#include "std_lib_facilities.h"

int main()
{
     vector<double> dists;
     cout << "Enter a sequence of distances between cities:\n";
     for (double dist; cin >> dist;)
	  dists.push_back(dist);

     if (dists.size() != 0) {
	  double sum = 0;
	  double max = dists[0];
	  double min = dists[0];
	  for (double x: dists) {
	       sum += x;
	       if (x < min)
		    min = x;
	       if (x > max)
		    max = x;
	  }
	  double average = sum / dists.size();
	  cout << "Total distance between cities is " << sum
	       << ".\nLargest distance between neighboring cities is " << max
	       << ".\nSmallest distance between neigboring cities is " << min
	       << ".\nMean distance is " << average << ".\n";
     } else {
	  cout << "No data!\n";
     }
}
