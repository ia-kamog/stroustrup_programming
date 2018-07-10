/*
  Exercise 7.10
  Use integers
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
  Number:
	Roman_number
  Name:
	[a-z_][A-Za-z0-9_]*
	
*/
#include "std_lib_facilities.h"
#include "roman.h"
#include "token_stream.h"
#include "symbol_table.h"

Roman_int statement();
Roman_int declaration(bool constant);
Roman_int expression();
Roman_int term();
Roman_int primary();
void calculate();
void clean_up_mess();
void usage();

Token_stream ts;
Symbol_table st;

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
	    if (t.kind == help)
		usage();
	    else if (t.kind==quit)
		return;
	    else {
		ts.putback(t);
		cout << result << statement() << '\n';
	    }
	} catch (exception& e) {
	    cerr << e.what() << '\n';
	    clean_up_mess();
	}
}

void clean_up_mess()
{
    ts.ignore(print);
}

Roman_int statement()
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

Roman_int declaration(bool constant)
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);
    Roman_int d = expression();
    st.define_name(var_name, d, constant);
    return d;
}

Roman_int expression()
{
    Roman_int left = term();
    Token t = ts.get();
    while (true) {
	switch (t.kind) {
	case '+':
	    left = left + term();
	    t = ts.get();
	    break;
	case '-':
	    left = left - term();
	    t = ts.get();
	    break;
	default:
	    ts.putback(t);
	    return left;
	}
    }
}

Roman_int term()
{
    Roman_int left = primary();
    Token t = ts.get();
    while (true) {
	switch (t.kind) {
	case '*':
	    left = left * primary();
	    t = ts.get();
	    break;
	case '/': {
	    Roman_int d = primary();
	    if (d == Roman_int{0}) error("divide by zero");
	    left /= d;
	    t = ts.get();
	    break;
	}
	case '%': {
	    Roman_int d = primary();
	    if (d == Roman_int{0}) error("divide by zero");
	    left %= d;
	    t = ts.get();
	    break;
	}
	default:
	    ts.putback(t);
	    return left;
	}
    }
}

Roman_int primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': {
	Roman_int d = expression();
	t = ts.get();
	if (t.kind != ')') {
	    ts.putback(t);
	    error("')' expected");
	}
	return d;
    }
    case '[': {
	Roman_int x = expression();
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
	return -primary();
    case '+':
	return primary();
    case name: {
	Token t2 = ts.get();
	Roman_int x;
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

void usage()
{
    cout << "This is a basic calculator.\n"
	"It supports operations with integer numbers\n"
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
