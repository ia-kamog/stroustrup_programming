/* Exercise 8.7
   Read and print names and ages */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Person {
     string name;
     int age;
};

static void read_names(vector<Person>&);
static void read_ages(vector<Person>&);
static void print_table(const vector<Person>&);

int main()
{
     size_t n;
     cin >> n;
     vector<Person> v(n);
     read_names(v);
     read_ages(v);
     sort(v.begin(), v.end(),
	  [](const Person& p1, const Person& p2) -> bool
	       { return p1.name < p2.name; });
     print_table(v);
}

void read_names(vector<Person>& v)
{
     for (size_t i = 0; i < v.size(); ++i)
	  cin >> v[i].name;
}

void read_ages(vector<Person>& v)
{
     for (size_t i = 0; i < v.size(); ++i) {
	  cout << v[i].name << ": " << flush;
	  cin >> v[i].age;
     }
}

void print_table(const vector<Person>& v)
{
     for (const Person& p: v)
	  cout << p.name << '\t' << p.age << '\n';
}
