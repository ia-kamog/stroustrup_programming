#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H
#include "std_lib_facilities.h"
const char number = '8';
const char quit = 'q';
const char help = 'h';
const char print = ';';
const char from = 'f';
const char to = 't';
const string prompt = "> ";
const string result = "= ";
const char let = 'L';
const char constant = 'C';
const char name = 'a';
const string declkey = "let";
const string constkey = "const";
const string quitkey = "quit";
const string helpkey = "help";
const string fromkey = "from";
const string tokey = "to";

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
    Token_stream():istr{&cin} {};
    Token get();
    void putback(Token);
    void ignore(char c);
    void set_source(istream& ist)
	{ if (istr != &cin)
		delete istr;
	    istr = &ist; }
    operator bool() { return is().good(); }
private:
    bool full {false};
    Token buffer;
    istream *istr;
    istream& is() { return *istr; }
};

#endif
