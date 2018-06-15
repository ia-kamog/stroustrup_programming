#include "token_stream.h"

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
     while (cin.get(ch) && ch != '\n' && isspace(ch));
     switch (ch) {
     case print: case '\n':
	  return Token{print};
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
	       else if (s == helpkey)
		    return Token{help};
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
