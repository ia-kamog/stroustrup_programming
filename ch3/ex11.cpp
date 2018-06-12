// Exercise 3.11: calculate money
#include "std_lib_facilities.h"
int main()
{
     cout << "How many pennies do you have?\n";
     int pennies {0};
     cin >> pennies;

     cout << "How many nickels do you have?\n";
     int nickels {0};
     cin >> nickels;

     cout << "How many dimes do you have?\n";
     int dimes {0};
     cin >> dimes;

     cout << "How many quarters do you have?\n";
     int quarters {0};
     cin >> quarters;

     cout << "How many half dollars do you have?\n";
     int half_dollars {0};
     cin >> half_dollars;

     cout << "How many dollar coins do you have?\n";
     int dollars {0};
     cin >> dollars;

     string yhv = "You have ";
     string s = "s";
     string pt = ".\n";
     cout <<yhv<<pennies<<" penn"<<(pennies==1?"y":"ies")<<pt
	  <<yhv<<nickels<<" nickel"<<(nickels==1?"":s)<<pt
	  <<yhv<<dimes<<" dime"<<(dimes==1?"":s)<<pt
	  <<yhv<<quarters<<" quarter"<<(quarters==1?"":s)<<pt
	  <<yhv<<half_dollars<<" half-dollar"<<(half_dollars==1?"":s)<<pt
	  <<yhv<<dollars<<" dollar"<<(dollars==1?"":s)<<pt;
     int cents = pennies + 5*nickels + 10*dimes
	  + 25*quarters + 50*half_dollars + 100*dollars;
     double total = cents;
     total /= 100;
     cout << "The value of all of your coins is " << cents
	  << " cents ($" << total << ").\n";
}
