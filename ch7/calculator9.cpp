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
     void ignore(char c);
private:
     bool full {false};
     Token buffer;
};

double expression();
double term();
double primary();
void calculate();
void clean_up_mess();

Token_stream ts;

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

int main() try
{
     calculate();
     return 0;
}
catch (exception& e) {
     cerr << e.what() << '\n';
     return 1;
}
catch (...) {
     cerr << "exception\n";
     return 2;
}

void calculate()
{
     while (cin)
	  try {
	       cout << prompt;
	       Token t = ts.get();
	       while (t.kind==print) t=ts.get();
	       if (t.kind==quit) return;
	       ts.putback(t);
	       cout << result << expression() << '\n';
	  } catch (exception& e) {
	       cerr << e.what() << '\n';
	       clean_up_mess();
	  }
}

void clean_up_mess()
{
     ts.ignore(print);
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
	  case '%': {
	       double d = primary();
	       if (d == 0) error("divide by zero");
	       left = fmod(left, d);
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
     switch (t.kind) {
     case '(': {
	  double d = expression();
	  t = ts.get();
	  if (t.kind != ')') {
	       ts.putback(t);
	       error("')' expected");
	  }
	  return d;
     }
     case number:
	  return t.value;
     case '-':
	  return -primary();
     case '+':
	  return primary();
     default:
	  error("primary expected");
     }
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
     case print: case quit:
     case '(': case ')':
     case '+': case '-': case '*': case '/': case '%':
	  return Token{ch};
     case '.':
     case '0': case '1': case '2': case '3': case '4':
     case '5': case '6': case '7': case '8': case '9':
     {
	  cin.putback(ch);
	  double val;
	  cin >> val;
	  return Token{number,val};
     }
     default:
	  error("Bad token");
     }
}

void Token_stream::ignore(char c)
{
     if (full && c==buffer.kind) {
	  full = false;
	  return;
     }
     full = false;
     char ch;
     while (cin>>ch)
	  if (ch==c) return;
}
