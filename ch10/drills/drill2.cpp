#include "point.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    constexpr int npoints = 7;
    vector<Point> original_points{npoints};
    for (int i = 0; cin && i < npoints; ++i)
	cin >> original_points[i];
    if (!cin) {
	cerr << "Failure while reading " << npoints << " points!\n";
	return 1;
    }
}
