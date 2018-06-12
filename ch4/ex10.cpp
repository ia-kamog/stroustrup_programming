// Exercise 4.10: rock-scissor-paper game
#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <random>
#include <cctype>

enum class Move {rock, scissors, paper};
bool beats(Move m1, Move m2)
{
     return (m1 == Move::rock && m2 == Move::scissors) ||
	  (m1 == Move::scissors && m2 == Move::paper) ||
	  (m2 == Move::paper && m2 == Move::rock);
}

class Random_Move_Gen {
public:
     Random_Move_Gen() : dist(0,2) {}
     Move next() {
	  auto r = static_cast<Move>(dist(gen));
	  hist.push_back(r);
	  return r;
     }
     const std::vector<Move>& history() const { return hist; }
private:
     std::default_random_engine gen;
     std::uniform_int_distribution<int> dist;
     std::vector<Move> hist;
};

std::ostream& operator<<(std::ostream &os, const Move& m)
{
     switch (m) {
     case Move::rock:
	  os << "Rock";
	  break;
     case Move::scissors:
	  os << "Scissors";
	  break;
     case Move::paper:
	  os << "Paper";
	  break;
     }
     return os;
}

std::istream& operator>>(std::istream &is, Move& m)
{
     std::string in;
     bool success = (is >> in).good();
     if (!success)
	  return is;
     switch (std::tolower(in[0])) {
     case 'r': m = Move::rock; break;
     case 'p': m = Move::paper; break;
     case 's': m = Move::scissors; break;
     default: is.setstate(std::ios::failbit); break;
     }
     return is;
}

bool get_move(Move &m)
{
     std::cout << "Enter a move: " << std::flush;
     std::cin >> m;
     return std::cin.good();
}

int main()
{
     Random_Move_Gen gen;
     int wins = 0;
     int loses = 0;
     int draws = 0;
     std::vector<Move> user_hist;
     for (Move input; get_move(input);) {
	  user_hist.push_back(input);
	  Move computer_move = gen.next();
	  std::cout << "Computer does " << computer_move << '\n';
	  if (input == computer_move) {
	       ++draws;
	       std::cout << "A draw!";
	  } else if (beats(computer_move, input)) {
	       ++loses;
	       std::cout << "You lost!";
	  } else {
	       ++wins;
	       std::cout << "You won!";
	  }
	  std::cout << std::endl;
     }
     std::cout << "\nLoses: " << loses
	       << "\nWins:  " << wins
	       << "\nDraws: " << draws
	       << std::endl;
     std::cout << "Print history (y,n)? " << std::flush;
     char in;
     std::cin.clear();
     std::cin >> in;
     if (in == 'y') {
	  std::cout.width(20);
	  std::cout << std::left << "Computer" << std::left << "User\n";
	  for (std::size_t i = 0; i < user_hist.size(); ++i) {
	       std::cout.width(20);
	       std::cout << std::left << gen.history()[i]
			 << std::left << user_hist[i] << '\n';
	  }
     }
}
