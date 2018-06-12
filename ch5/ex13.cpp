// Exercise 5.13.
// Bulls and cows game.
#include "std_lib_facilities.h"
bool is_member(int s, vector<int>& v)
{
     for (int x : v)
	  if (x==s)
	       return true;
     return false;
}

vector<int> make_game()
{
     vector<int> r;
     while (r.size() != 4) {
	  int x = randint(10);
	  if (!is_member(x, r))
	       r.push_back(x);
     }
     return r;
}

vector<int> read_guess()
{
     cout << "Enter your guess:\n";
     vector<int> v(4);
     for (int i = 0; i < v.size(); ++i)
	  if (!(cin >> v[i]))
	       error("End of input");
     return v;
}

int direct_matches(vector<int>& u, vector<int>& g)
{
     int s = 0;
     for (size_t i = 0; i < u.size(); ++i)
	  s += (u[i] == g[i]);
     return s;
}

int total_matches(vector<int>& u, vector<int>& g)
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
     vector<int> game = make_game();
     do {
	  vector<int> user = read_guess();
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
