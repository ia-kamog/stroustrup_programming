// compose a letter from user input
#include "std_lib_facilities.h"

int main()
{
     cout << "Enter the name of the person you want to write to\n";
     string first_name;
     cin >> first_name;

     cout << "Enter his or her age\n";
     int age {0};
     cin >> age;
     if (age <= 0 || age >= 110)
	  simple_error("you're kidding!");
     
     cout << "Enter the name of your friend\n";
     string friend_name;
     cin >> friend_name;
     
     cout << "Enter the sex of the friend\n";
     char friend_sex {0};
     cin >> friend_sex;
     
     cout << "Dear " << first_name << ",\n"
	  << "  How are you? I am fine. I miss you.\n"
	  << "Beavers are very fluffy. Wallabies are \n"
	  << "fluffy and kind.\n"
	  << "  Have you seen " << friend_name << " lately?"
	  << " If you\nsee " << friend_name << ", please ask ";
     if (friend_sex == 'm') cout << "him";
     else cout << "her";
     cout << " to call me.\n"
	  << "  I hear you just had a birthday and\n"
	  << "you are " << age << " years old.\n";
     if (age < 12)
	  cout << "Next year you will be " << age+1 <<".\n";
     else if (age == 17)
	  cout << "Next yaer you will be able to vote.\n";
     else if (age > 70)
	  cout << "I hope you are enjoying retirement.\n";
     cout << "           Yours sincerely,\n\n"
	  << "                      Art.\n";
}
