/*
  Exercise 8.1
  Token_stream constructor takes istream.
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
#include "std_lib_facilities.h"
#include "token_stream.h"
#include "symbol_table.h"
#include "parser.h"

void calculate(Token_stream&, Symbol_table&);
void clean_up_mess(Token_stream&);
void usage();

int main() try
{
     Token_stream ts(cin);
     Symbol_table st;

     st.define_name("pi", 3.1415926535, true);
     st.define_name("e", 2.7182818284, true);
     calculate(ts, st);
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

void calculate(Token_stream& ts, Symbol_table& st)
{
     while (cin)
	  try {
	       cout << prompt;
	       Token t = ts.get();
	       while (t.kind==print) t=ts.get();
	       if (t.kind == help)
		    usage();
	       else if (t.kind==quit)
		    return;
	       else {
		    ts.putback(t);
		    cout << result << statement(ts, st) << '\n';
	       }
	  } catch (exception& e) {
	       cerr << e.what() << '\n';
	       clean_up_mess(ts);
	  }
}

void clean_up_mess(Token_stream& ts)
{
     ts.ignore(print);
}

void usage()
{
     cout << "This is a basic calculator.\n"
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
