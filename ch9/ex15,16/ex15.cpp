#include <iostream>
#include "money.h"

using namespace std;

int main()
{
    Money m1, m2;
    double k;

    cout << "m1: " << flush;
    cin >> m1;
    cout << "m2: " << flush;
    cin >> m2;
    cout << "k: " << flush;
    cin >> k;

    cout << "m1 == " << m1 << '\n'
	 << "m2 == " << m2 << '\n'
	 << "USD(m1) == " << m1.convert(Currency::USD) << '\n'
	 << "USD(m2) == " << m2.convert(Currency::USD) << '\n'
	 << "m1.total_units() == " << m1.total_units() << '\n'
	 << "m2.total_units() == " << m2.total_units() << '\n'
	 << "m1.whole_units() == " << m1.whole_units() << '\n'
	 << "m2.whole_units() == " << m2.whole_units() << '\n'
	 << "m1.small_units() == " << m1.small_units() << '\n'
	 << "m2.small_units() == " << m2.small_units() << '\n'
	 << "m1 + m2 == " << (m1+m2) << '\n'
	 << "m1 - m1 == " << (m1-m2) << '\n'
	 << "k*m1 == " << (k*m1) << '\n'
	 << "k*m2 == " << (k*m2) << '\n'
	 << "m1/k == " << (m1/k) << '\n'
	 << "m2/k == " << (m2/k) << '\n'
	 << "m1 < m2 == " << (m1<m2) << '\n'
	 << "m1 > m2 == " << (m1>m2) << '\n'
	 << "m1 == m2 == " << (m1==m2) << '\n'
	 << "m1 != m2 == " << (m1!=m2) << '\n';
}
