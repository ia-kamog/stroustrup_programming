/*
  Exercise 7.4
  Make a class for var_table
  Grammar:
  Calculation:
	Statement
	Print
	Quit
  Statement:
	'let' Declaration
	'const' Declaration
	Expression
  Declaration:
	Name '=' Expression
  Expression:
	Term
	Expression '+' Term
	Expression '-' Term
  Term:
	Primary
	Term '*' Primary
	Term '/' Primary
	Term '%' Primary
  Primary:
	Name
	Name '=' Expression
	Number
	- Primary
	+ Primary
  Number:
	.[0-9]+(e-?[0-9]+)?
	[0-9]+(.[0-9]*)?(e-?[0-9]+)?
  Name:
	[A-Za-z_][A-Za-z0-9_]*
	
*/
#include "std_lib_facilities.h"
#include "token_stream.h"
#include "symbol_table.h"

double statement();
double declaration(bool constant);
double expression();
double term();
double primary();
void calculate();
void clean_up_mess();

Token_stream ts;
Symbol_table st;

int main() try
{
     st.define_name("pi", 3.1415926535, true);
     st.define_name("e", 2.7182818284, true);
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
	       cout << result << statement() << '\n';
	  } catch (exception& e) {
	       cerr << e.what() << '\n';
	       clean_up_mess();
	  }
}

void clean_up_mess()
{
     ts.ignore(print);
}

double statement()
{
     Token t = ts.get();
     switch (t.kind) {
     case let:
	  return declaration(false);
     case constant:
	  return declaration(true);
     default:
	  ts.putback(t);
	  return expression();
     }
}

double declaration(bool constant)
{
     Token t = ts.get();
     if (t.kind != name) error("name expected in declaration");
     string var_name = t.name;
     Token t2 = ts.get();
     if (t2.kind != '=') error("= missing in declaration of ", var_name);
     double d = expression();
     st.define_name(var_name, d, constant);
     return d;
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
     case name: {
	  Token t2 = ts.get();
	  double x;
	  if (t2.kind == '=') {
	       x = expression();
	       st.set_value(t.name, x);
	  } else {
	       ts.putback(t2);
	       x = st.get_value(t.name);
	  }
	  return x;
     }
     default:
	  error("primary expected");
     }
}
