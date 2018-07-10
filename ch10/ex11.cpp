#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>

using namespace std;
int count(istream& is)
{
    int sum = 0;
    for (char ch; is.get(ch);) {
	if (isdigit(ch)) {
	    is.unget();
	    int x {0};
	    if (is >> x && (is.get(ch) && isspace(ch) || is.eof()))
		sum += x;
	}
    }
    return sum;
}
	
int main()
{
    int s = count(cin);
    cout << "sum = " << s << '\n';
}
