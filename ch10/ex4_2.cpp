#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct Reading {
    int hour;
    double temperature;
    char unit;
};

double cels_to_fahr(double c)
{
    return 9.0/5.0*c+32.0;
}
ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature << r.unit;
}

istream& operator>>(istream& is, Reading& r)
{
    return is >> r.hour >> r.temperature >> r.unit;
}

void stats(const vector<Reading>& in, double& mean, double& median)
{
    if (in.size() == 0)
	return;
    vector<double> values(in.size());
    double sum = 0;
    for (size_t i = 0; i < in.size(); ++i) {
	values[i] = in[i].temperature;
	sum += values[i];
    }

    sort(values.begin(), values.end());
    mean = sum / in.size();
    median = values[in.size()/2];
}

int main()
{
    ifstream ifs{"raw_temps.txt"};
    if (!ifs)
	throw runtime_error("can't open file for reading");
    vector<Reading> data;
    for (Reading r; ifs >> r;) {
	if (r.unit == 'c') {
	    r.temperature = cels_to_fahr(r.temperature);
	    r.unit = 'f';
	}
	data.push_back(r);
    }
    double median = 0, mean = 0;
    stats(data, mean, median);
    cout << "mean = " << mean << 'f' << '\n'
	 << "median = " << median << 'f' << '\n';
}
