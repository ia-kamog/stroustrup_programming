#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

constexpr int not_a_month = -1;
constexpr int not_a_reading = -7777;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;
vector<string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul",
    "aug", "sep", "oct", "nov", "dec"
};
vector<string> month_print_tbl = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};
struct Reading {
    int day;
    int hour;
    double temperature;
};

struct Day {
    vector<double> hour{vector<double>(24,not_a_reading)};
};

struct Month {
    int month {not_a_month};
    vector<Day> day{32};
};

struct Year {
    int year;
    vector<Month> month{12};
};

istream& operator>>(istream&, Reading&);
istream& operator>>(istream&, Month&);
istream& operator>>(istream&, Year&);
bool is_valid(const Reading&);
int month_to_int(string s);
string int_to_month(int i);
void end_of_loop(istream& ist, char term, const string& message);
void print_year(ostream&, const Year&);

int main() try
{
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if (!ist) throw runtime_error("can't open input file " + iname);
    ist.exceptions(ist.exceptions()|ios_base::badbit);
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if (!ost)
	throw runtime_error("can't open output file " + oname);

    vector<Year> ys;
    while (true) {
	Year y;
	if (!(ist >> y))
	    break;
	ys.push_back(y);
    }
    cout << "read " << ys.size() << " year of readings\n";

    for (Year& y: ys) print_year(ost,y);
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
} catch (...) {
    cerr << "Unknown exception!";
    return 2;
}

istream& operator>>(istream& is, Reading& r)
{
    char ch1;
    if (is >> ch1 && ch1 != '(') {
	is.unget();
	is.clear(ios_base::failbit);
	return is;
    }

    char ch2;
    int d, h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')
	throw runtime_error{"bad reading"};
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m)
{
    char ch = 0;
    if (is >> ch && ch != '{') {
	is.unget();
	is.clear(ios_base::failbit);
	return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month")
	throw runtime_error{"bad start of month"};
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r;) {
	if (is_valid(r)) {
	    if (m.day[r.day].hour[r.hour] != not_a_reading)
		++duplicates;
	    m.day[r.day].hour[r.hour] = r.temperature;
	} else {
	    ++invalids;
	}
    }
    if (invalids)
	throw runtime_error{"invalid reading in month " +
		to_string(invalids)};
    if (duplicates)
	throw runtime_error{"duplicate readings in month " +
		to_string(duplicates)};
    end_of_loop(is,'}',"bad end of month");
    return is;
}

bool is_valid(const Reading& r)
{
    if (r.day < 1 || 31 < r.day) return false;
    if (r.hour < 0 || 23 < r.hour) return false;
    if (r.temperature < implausible_min ||
	implausible_max < r.temperature)
	return false;
    return true;
}

istream& operator>>(istream& is, Year& y)
{
    char ch;
    is >> ch;
    if (!is) return is;
    if (ch != '{') {
	is.unget();
	is.clear(ios_base::failbit);
	return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year")
	throw runtime_error("bad start of year");
    y.year = yy;

    while (true) {
	Month m;
	if (!(is>>m)) break;
	y.month[m.month] = m;
    }
    end_of_loop(is,'}',"bad end of year");
    return is;
}

int month_to_int(string s)
{
    for (int i = 0; i < month_input_tbl.size(); ++i)
	if (s == month_input_tbl[i])
	    return i;
    return -1;
}

string int_to_month(int i)
{
    if (i < 0 || month_print_tbl.size() <= i)
	throw runtime_error{"bad month index"};
    return month_print_tbl[i];
}

void end_of_loop(istream& is, char term, const string& message)
{
    if (is.fail()) {
	is.clear();
	char ch;
	if (is >> ch && ch == term)
	    return;
	throw runtime_error{message};
    }
}

void print_year(ostream& os, const Year& y)
{
    os << "{ year " << y.year << '\n';
    for (int i = 0; i < y.month.size(); ++i) {
	const Month& m = y.month[i];
	if (m.month != not_a_month) {
	    os << "\t{ month " << int_to_month(m.month) << '\n';
	    for (int j = 1; j < m.day.size(); ++j) {
		const Day& d = m.day[j];
		for (int k = 0; k < d.hour.size(); ++k)
		    if (d.hour[k] != not_a_reading)
			os << "\t\t(" << j << ' ' << k
			   << ' ' << d.hour[k] << ")\n";
	    }
	    os << "\t}\n";
	}
    }
    os << "}\n";
}
	
