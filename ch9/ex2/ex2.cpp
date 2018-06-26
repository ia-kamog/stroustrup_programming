#include "name_pairs.h"
#include <iostream>
using namespace std;
int main()
{
     Name_pairs v;
     v.read_names();
     v.read_ages();
     v.print();
     cout << "--------------\n";
     v.sort();
     v.print();
}
