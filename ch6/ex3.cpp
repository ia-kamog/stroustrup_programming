/*-
 * Exercise 6.3.
 * Simple calculator supporting +,-,*,/,(,),{,},!.
 * Grammar of the calculator:
 * Expression:
 *	Term
 *	Expression '+' Term
 *	Expression '-' Term
 * Term:
 *	Primary
 *	Term '*' Primary
 *	Term '/' Primary
 * Primary:
 *	Number
 *	Primary '!'
 *	'(' Expression ')'
 *	'{' Expression '}'
 */

#include "std_lib_facilities.h"

class Token {
public:
     char kind;
     double value;
};

class Token_stream {
public:
     Token_stream() {};
     Token get();
     void putback(Token);
private:
     bool full {false};
     Token buffer;
};

double expression();
double term();
double primary();
int fact(int x);

Token_stream ts;

int main() try
{
     double val = 0;
     while (cin) {
	  Token t = ts.get();
	  if (t.kind == 'q')
	       break;
	  ts.putback(t);
	  val = expression();
	  t = ts.get();
	  if (t.kind == ';')
	       cout << '=' << val << '\n';
	  else if (t.kind == 'q')
	       break;
	  else
	       ts.putback(t);
     }
}
catch (exception& e) {
     cerr << e.what() << '\n';
     return 1;
}
catch (...) {
     cerr << "exception\n";
     return 2;
}

double expression()
{
     double left = term();
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '+':
	       left += term();
	       t = ts.get();
	       break;
	  case '-':
	       left -= term();
	       t = ts.get();
	       break;
	  default:
	       ts.putback(t);
	       return left;
	  }
     }
}

double term()
{
     double left = primary();
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '*':
	       left *= primary();
	       t = ts.get();
	       break;
	  case '/': {
	       double d = primary();
	       if (d == 0) error("divide by zero");
	       left /= d;
	       t = ts.get();
	       break;
	  }
	  default:
	       ts.putback(t);
	       return left;
	  }
     }
}

double primary()
{
     Token t = ts.get();
     char close = '}';
     double res;
     switch (t.kind) {
     case '(':
	  close = ')';
     case '{':
     {
	  double d = expression();
	  t = ts.get();
	  if (t.kind != close) {
	       ts.putback(t);
	       error("')' expected");
	  }
	  res = d;
	  break;
     }
     case '8':
	  res = t.value;
	  break;
     default:
	  error("primary expected");
     }

     for (t=ts.get(); t.kind=='!'; t=ts.get())
	  res = fact(res);
     ts.putback(t);
     return res;
}

void Token_stream::putback(Token t)
{
     buffer = t;
     full = true;
}

Token Token_stream::get()
{
     if (full) {
	  full = false;
	  return buffer;
     }
     char ch;
     cin >> ch;
     switch (ch) {
     case ';':
     case 'q':
     case '(': case ')': case '{': case '}':
     case '+': case '-': case '*': case '/': case '!':
	  return Token{ch};
     case '.':
     case '0': case '1': case '2': case '3': case '4':
     case '5': case '6': case '7': case '8': case '9':
     {
	  cin.putback(ch);
	  double val;
	  cin >> val;
	  return Token{'8',val};
     }
     default:
	  error("Bad token");
     }
}

int fact(int x)
{
     if (x < 0)
	  error("Factorial of a negative number!");
     int res = 1;
     for (int i=1; i<=x; i++)
	  res *= i;
     return res;
}
