#include "std_lib_facilities.h"

class Token {
public:
     char kind;
     double value;
};

Token get_token();
double expression();
double term();
double primary();

int main() try
{
     while (cin)
	  cout << "=" << expression() << '\n';
} catch (exception& e) {
     cerr << e.what() << '\n';
     return 1;
} catch (...) {
     cerr << "exception\n";
     return 2;
}

double expression()
{
     double left = term();
     Token t = get_token();
     while (true) {
	  switch (t.kind) {
	  case '+':
	       left += term();
	       t = get_token();
	       break;
	  case '-':
	       left -= term();
	       t = get_token();
	       break;
	  default:
	       return left;
	  }
     }
}

double term()
{
     double left = primary();
     Token t= get_token();
     while (true) {
	  switch (t.kind) {
	  case '*':
	       left *= primary();
	       t = get_token();
	       break;
	  case '/': {
	       double d = primary();
	       if (d == 0) error("divide by zero");
	       left /= d;
	       t = get_token();
	       break;
	  }
	  default:
	       return left;
	  }
     }
}

double primary()
{
     Token t = get_token();
     switch (t.kind) {
     case '(': {
	  double d = expression();
	  t = get_token();
	  if (t.kind != ')') error("')' expected");
	  return d;
     }
     case '8':
	  return t.value;
     default:
	  error("primary expected");
     }
}

Token get_token()
{
     char p;
     cin >> p;
     cin.putback(p);
     if (isdigit(p) || p=='.') {
	  double d;
	  cin >> d;
	  if (!cin)
	       error("End");
	  return Token{'8', d};
     } else if (p=='(' || p==')' ||
		p=='+' || p=='-' ||
		p=='*' || p=='/') {
	  char ch;
	  cin >> ch;
	  if (!cin)
	       error("End");
	  return Token{p};
     } else
	  error("Bad token");
}
