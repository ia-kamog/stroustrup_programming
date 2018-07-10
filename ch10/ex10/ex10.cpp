/*
  Exercise 10.10
  Grammar:
  Calculation:
	Statement
	Calculation Statement
	Print
	Quit
	Help
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
	'(' Expression ')'
	'[' Expression ']'
  Number:
	.[0-9]+(e-?[0-9]+)?
	[0-9]+(.[0-9]*)?(e-?[0-9]+)?
  Name:
	[A-Za-z_][A-Za-z0-9_]*
	
*/
#include <fstream>
#include "std_lib_facilities.h"
#include "token_stream.h"
#include "symbol_table.h"

double statement(Token_stream& ts);
double declaration(Token_stream& ts, bool constant);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);
void calculate(Token_stream& ts);
void clean_up_mess(Token_stream& ts);
void usage();

Symbol_table st;
ostream *out {&cout};

int main() try
{
     st.define_name("pi", 3.1415926535, true);
     st.define_name("e", 2.7182818284, true);
     Token_stream ts;
     calculate(ts);
     *out << flush;
     return 0;
}
catch (exception& e) {
     *out << e.what() << '\n';
     return 1;
}
catch (...) {
     *out << "exception\n";
     return 2;
}

void calculate(Token_stream& ts)
{
     while (ts)
	  try {
	       *out << prompt;
	       Token t = ts.get();
	       while (t.kind==print) t=ts.get();
	       if (t.kind == help)
		    usage();
	       else if (t.kind==quit)
		    return;
	       else {
		    ts.putback(t);
		    *out << result << statement(ts) << '\n';
	       }
	  } catch (exception& e) {
	      *out << e.what() << '\n';
	       clean_up_mess(ts);
	  }
}

void clean_up_mess(Token_stream& ts)
{
     ts.ignore(print);
}

double statement(Token_stream& ts)
{
     Token t = ts.get();
     switch (t.kind) {
     case let:
	 return declaration(ts,false);
     case constant:
	 return declaration(ts,true);
     case from: {
	 Token t = ts.get();
	 if (t.kind != name) {
	     ts.putback(t);
	     error("name expected");
	 }
	 if (t.name != "cin") {
	     ifstream *ifs = new ifstream{t.name};
	     if (!ifs)
		 error("can't open ", t.name);
	     ts.set_source(*ifs);
	 } else
	     ts.set_source(cin);
	 break;
     }
     case to: {
	 Token t = ts.get();
	 if (t.kind != name) {
	     ts.putback(t);
	     error("name expected");
	 }
	 if (t.name != "cout") {
	     ofstream *of = new ofstream{t.name};
	     if (!of)
		 error("can't open file for writing");
	     if (out != &cout) 
		 delete out;
	     out = of;
	 } else
	     out = &cout;
	 break;
     }
     default:
	 ts.putback(t);
	 return expression(ts);
     }
}

double declaration(Token_stream& ts, bool constant)
{
     Token t = ts.get();
     if (t.kind != name) error("name expected in declaration");
     string var_name = t.name;
     Token t2 = ts.get();
     if (t2.kind != '=') error("= missing in declaration of ", var_name);
     double d = expression(ts);
     st.define_name(var_name, d, constant);
     return d;
}

double expression(Token_stream& ts)
{
     double left = term(ts);
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '+':
	       left += term(ts);
	       t = ts.get();
	       break;
	  case '-':
	       left -= term(ts);
	       t = ts.get();
	       break;
	  default:
	       ts.putback(t);
	       return left;
	  }
     }
}

double term(Token_stream& ts)
{
     double left = primary(ts);
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '*':
	       left *= primary(ts);
	       t = ts.get();
	       break;
	  case '/': {
	       double d = primary(ts);
	       if (d == 0) error("divide by zero");
	       left /= d;
	       t = ts.get();
	       break;
	  }
	  case '%': {
	       double d = primary(ts);
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

double primary(Token_stream& ts)
{
     Token t = ts.get();
     switch (t.kind) {
     case '(': {
	  double d = expression(ts);
	  t = ts.get();
	  if (t.kind != ')') {
	       ts.putback(t);
	       error("')' expected");
	  }
	  return d;
     }
     case '[': {
	  int x = expression(ts);
	  Token t2 = ts.get();
	  if (t2.kind != ']') {
	       ts.putback(t2);
	       error("']' is expected");
	  }
	  return x;
     }
     case number:
	  return t.value;
     case '-':
	  return -primary(ts);
     case '+':
	  return primary(ts);
     case name: {
	  Token t2 = ts.get();
	  double x;
	  if (t2.kind == '=') {
	       x = expression(ts);
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

void usage()
{
     *out << "This is a basic calculator.\n"
	  "It supports operations with floating-point numbers\n"
	  "and variables. +,-,*,/ have usual meaning and precedence.\n"
	  "'(' and ')' are used to group subexpressions\n"
	  "'[' and ']' take the integer part from their argument\n"
	  "% means floating-point modulo: x%y = x-[x/y]*y\n"
	  "Expressions are separated with ';'\n"
	  "You can define a variable using 'let' keyword:\n"
	  "let x = 1;\n"
	  "Equality is available and returns a value."
	  << "To quit use " << quitkey << '\n';
}
