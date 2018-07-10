#include <fstream>
#include <ios>
#include <iostream>
#include <string>
using namespace std;
void merge(istream& is1, istream& is2, ostream& os)
{
    string s1, s2;
    is1 >> s1;
    is2 >> s2;
    while (is1 && is2) {
	if (s1 < s2) {
	    os << s1 << '\n';
	    is1 >> s1;
	} else {
	    os << s2 << '\n';
	    is2 >> s2;
	}
    }
    while (is1) {
	is1 >> s1;
	os << s1;
    }
    while (is2) {
	is2 >> s2;
	os << s2;
    }
}

int main()
{
    cout << "Input files: ";
    string f1, f2;
    cin >> f1 >> f2;
    cout << "Output file: ";
    string out;
    cin >> out;

    ifstream is1{f1}, is2{f2};
    ofstream of{out};
    if (!is1 || !is2 || !of)
	return 1;
    merge(is1, is2, of);
}
