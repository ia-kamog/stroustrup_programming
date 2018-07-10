#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
static int get_sum(const string& file);
int main() try
{
    string file;
    cout << "Filename: " << flush;
    cin >> file;

    int sum = get_sum(file);
    cout << "sum = " << sum << '\n';
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
int get_sum(const string& file)
{
    ifstream ist{file};
    int sum = 0;
    for (int i; ist >> i;)
	sum += i;
    if (ist.eof()) return sum;
    if (ist.bad())
	throw runtime_error("something bad with " + file);
    if (ist.fail())
	throw runtime_error("reading from " + file + " failed");
}
