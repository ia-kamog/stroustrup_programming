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

int main()
{
    vector<Reading> tempdata {
	{0,10},{1,9},{2,9},{3,9},{4,9},{5,9},
	{6,9},{7,9},{8,10},{9,13},{10,15},{11,17},
	{12,18},{13,19},{14,19},{15,20},{16,20},{17,17},
	{18,13},{19,12},{20,12},{21,10},{22,12},{23,11},
	{24,11},{25,11},{26,11},{27,11},{28,10},{29,10},
	{30,10},{31,9},{32,10},{33,12},{34,14},{35,18},
	{36,20},{37,21},{38,21},{39,21},{40,21},{41,18},
	{42,16},{43,12},{44,12},{45,10},{46,8},{47,8},
	{48,7}, {49,6}
    };

    ofstream ofs{"raw_temps.txt"};
    if (!ofs) throw runtime_error("can't open file!");
    for (auto& r: tempdata)
	ofs << r;
}
