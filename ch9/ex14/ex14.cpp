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
	 << "m1.total_cents() == " << m1.total_cents() << '\n'
	 << "m2.total_cents() == " << m2.total_cents() << '\n'
	 << "m1.dollars() == " << m1.dollars() << '\n'
	 << "m2.dollars() == " << m2.dollars() << '\n'
	 << "m1.cents() == " << m1.cents() << '\n'
	 << "m2.cents() == " << m2.cents() << '\n'
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
