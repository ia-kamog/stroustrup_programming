/*
  Exercise 7.3
  Add constants
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

class Token {
public:
     char kind;
     double value;
     string name;
     Token() {}
     Token(char ch) :kind{ch} {}
     Token(char ch, double val) :kind{ch}, value{val} {}
     Token(char ch, string n) :kind{ch}, name{n} {}
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

class Variable {
public:
     string name;
     double value;
     bool is_const;
};

double statement();
double declaration(bool constant);
bool is_declared(string var);
double define_name(string var, double val, bool constant);
double expression();
double term();
double primary();
void calculate();
void clean_up_mess();
double get_value(string s);
void set_value(string s, double d);

Token_stream ts;
vector<Variable> var_table;

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char let = 'L';
const char constant = 'C';
const char name = 'a';
const string declkey = "let";
const string constkey = "const";
const string quitkey = "q";

int main() try
{
     define_name("pi", 3.1415926535, true);
     define_name("e", 2.7182818284, true);
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
     define_name(var_name, d, constant);
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
	       set_value(t.name, x);
	  } else {
	       ts.putback(t2);
	       x = get_value(t.name);
	  }
	  return x;
     }
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
     case print:
     case '(': case ')': case '=':
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
	  if (isalpha(ch) || ch == '_') {
	       string s;
	       s += ch;
	       while (cin.get(ch) &&
		      (isalpha(ch) || isdigit(ch) || ch == '_'))
		    s += ch;
	       cin.putback(ch);
	       if (s == quitkey)
		    return Token{quit};
	       else if (s == declkey)
		    return Token{let};
	       else if (s == constkey)
		    return Token{constant};
	       return Token{name,s};
	  }
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

double get_value(string s)
{
     for (const Variable& v: var_table)
	  if (v.name == s) return v.value;
     error("get: undefined variable ", s);
}

void set_value(string s, double d)
{
     for (Variable& v : var_table)
	  if (v.name == s) {
	       if (v.is_const)
		    error("attempt to modify the constant ", v.name);
	       v.value = d;
	       return;
	  }
     error("set: undefined variable ", s);
}

bool is_declared(string var)
{
     for (const Variable& v : var_table)
	  if (v.name == var) return true;
     return false;
}

double define_name(string var, double val, bool constant)
{
     if (is_declared(var)) error(var, " declared twice");
     var_table.push_back(Variable{var, val, constant});
     return val;
}
