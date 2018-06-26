#include "name_pairs.h"
#include <iostream>
using namespace std;
int main()
{
     Name_pairs v;
     v.read_names();
     v.read_ages();
     cout << v;
     cout << "--------------\n";
     v.sort();
     cout << v;
}
