#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using namespace std;;

void copy(istream& is, ostream& os)
{
    char ch;
    while (is.get(ch))
	os.put(ch);
}

void copy_file(const string& fn)
{
    ifstream is{fn};
    if (!is)
	return;
    copy(is, cout);
}

int main()
{
    string fn1, fn2;
    cin >> fn1 >> fn2;
    copy_file(fn1);
    copy_file(fn2);
}
