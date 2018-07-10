#include "point.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

constexpr size_t npoints = 7;
const string file = "mydata.txt";

static vector<Point> read_points(istream&, size_t);
static void print_points(ostream&, const vector<Point>&);

int main() try
{
    vector<Point> original_points{read_points(cin, npoints)};
    ofstream ost{file};
    if (!ost) throw runtime_error{"can't open " + file + " for output"};
    print_points(ost, original_points);
    ost.close();
    ifstream ist{file};
    if (!ist) throw runtime_error{"can't open " + file + " for input"};
    vector<Point> processed_points{read_points(ist, npoints)};
    for (size_t i = 0; i < npoints; ++i)
	cout << original_points[i] << '\t'
	     << processed_points[i] << '\n';
    for (size_t i = 0; i < npoints; ++i)
	if (original_points[i] != processed_points[i])
	    cout << "Something's wrong!\n";
    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}

vector<Point> read_points(istream& is, size_t sz)
{
    vector<Point> ps {sz};
    for (int i = 0; is && i < sz; ++i)
	is >> ps[i];
    if (!is)
	throw runtime_error("failure reading " + to_string(sz) + "points");
    return ps;
}

void print_points(ostream& os, const vector<Point>& ps)
{
    for (auto& p: ps)
	os << p << '\n';
}
