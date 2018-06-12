// Exercise 6.8.
// Bulls and cows game.
#include "std_lib_facilities.h"

bool is_member(int s, vector<char>& v)
{
     for (int x : v)
	  if (x==s)
	       return true;
     return false;
}

vector<char> make_game()
{
     vector<char> r;
     while (r.size() != 4) {
	  char x = randint(26) + 'a';
	  if (!is_member(x, r))
	       r.push_back(x);
     }
     return r;
}

vector<char> read_guess()
{
     cout << "Enter your guess:\n";
     vector<char> v(4);
     for (int i = 0; i < v.size(); ++i)
	  if (!(cin >> v[i]))
	       error("End of input");
     return v;
}

int direct_matches(vector<char>& u, vector<char>& g)
{
     int s = 0;
     for (size_t i = 0; i < u.size(); ++i)
	  s += (u[i] == g[i]);
     return s;
}

int total_matches(vector<char>& u, vector<char>& g)
{
     int s = 0;
     for (size_t i = 0; i < u.size(); ++i)
	  s += is_member(u[i], g);
     return s;
}

void print_result(int cows, int bulls)
{
     cout << bulls << " bull";
     if (bulls != 1)
	  cout << 's';
     cout << " and " << cows << " cow";
     if (cows != 1)
	  cout << 's';
     cout << '\n';
}

void play_game()
{
     int bulls = 0, cows = 0;
     vector<char> game = make_game();
     do {
	  vector<char> user = read_guess();
	  bulls = direct_matches(user, game);
	  cows = total_matches(user, game) - bulls;
	  print_result(cows, bulls);
     } while (bulls != game.size());
     cout << "You won!\n";
}

bool ask_to_play()
{
     cout << "Would you like to play the game of Bulls and Cows (y/n)?\n";
     char yn;
     cin >> yn;
     if (!cin)
	  return false;
     switch (yn) {
     case 'Y': case 'y':
	  return true;
     case 'N': case 'n':
	  return false;
     default:
	  cerr << "Bad input: " << yn << ".\n";
	  return ask_to_play();
     }
}

void init_rand()
{
     cout << "Enter a random integer:\n";
     int n;
     cin >> n;
     srand(n);
}

int main()
{
     init_rand();
     while (ask_to_play())
	  play_game();
}
