#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct Reading {
    int hour;
    double temperature;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature << '\n';
}

istream& operator>>(istream& is, Reading& r)
{
    return is >> r.hour >> r.temperature;
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
    for (Reading r; ifs >> r;)
	data.push_back(r);
    double median = 0, mean = 0;
    stats(data, mean, median);
    cout << "mean = " << mean << '\n'
	 << "median = " << median << '\n';
}
