#include "parser.h"
#include "token_stream.h"
#include "symbol_table.h"

static double primary(Token_stream&, Symbol_table&);
static double term(Token_stream&, Symbol_table&);
static double expression(Token_stream&, Symbol_table&);
static double declaration(Token_stream&, Symbol_table&, bool constant);

double statement(Token_stream& ts, Symbol_table& st)
{
     Token t = ts.get();
     switch (t.kind) {
     case let:
	  return declaration(ts, st, false);
     case constant:
	  return declaration(ts, st, true);
     default:
	  ts.putback(t);
	  return expression(ts, st);
     }
}

double declaration(Token_stream &ts, Symbol_table& st, bool constant)
{
     Token t = ts.get();
     if (t.kind != name) error("name expected in declaration");
     string var_name = t.name;
     Token t2 = ts.get();
     if (t2.kind != '=') error("= missing in declaration of ", var_name);
     double d = expression(ts, st);
     st.define_name(var_name, d, constant);
     return d;
}

double expression(Token_stream& ts, Symbol_table& st)
{
     double left = term(ts, st);
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '+':
	       left += term(ts, st);
	       t = ts.get();
	       break;
	  case '-':
	       left -= term(ts, st);
	       t = ts.get();
	       break;
	  default:
	       ts.putback(t);
	       return left;
	  }
     }
}

double term(Token_stream& ts, Symbol_table& st)
{
     double left = primary(ts, st);
     Token t = ts.get();
     while (true) {
	  switch (t.kind) {
	  case '*':
	       left *= primary(ts, st);
	       t = ts.get();
	       break;
	  case '/': {
	       double d = primary(ts, st);
	       if (d == 0) error("divide by zero");
	       left /= d;
	       t = ts.get();
	       break;
	  }
	  case '%': {
	       double d = primary(ts, st);
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

double primary(Token_stream& ts, Symbol_table& st)
{
     Token t = ts.get();
     switch (t.kind) {
     case '(': {
	  double d = expression(ts, st);
	  t = ts.get();
	  if (t.kind != ')') {
	       ts.putback(t);
	       error("')' expected");
	  }
	  return d;
     }
     case '[': {
	  int x = expression(ts, st);
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
	  return -primary(ts, st);
     case '+':
	  return primary(ts, st);
     case name: {
	  Token t2 = ts.get();
	  double x;
	  if (t2.kind == '=') {
	       x = expression(ts, st);
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
