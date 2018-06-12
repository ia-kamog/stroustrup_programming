// Exercise 6.1
// Recognize simple English sentences according to the grammar:
// Terminated_Sentence:
//	Sentence '.'
// Sentence:
//	Noun Verb
//	Sentence Conjunction Sentence
// Conjunction:
//	"and"
//	"or"
//	"but"
// Noun:
//	"C++"
//	"birds"
//	"fish"
// Verb:
//	"rules"
//	"fly"
//	"swim"

#include "std_lib_facilities.h"

class Word_stream {
public:
     Word_stream();
     string get();
     void putback(string);
     const string& peek();
private:
     string buffer;
     bool full;
};

const vector<string> conjunctions = { "and", "or", "but" };
const vector<string> nouns = { "birds", "fish", "C++" };
const vector<string> verbs = { "rules", "fly", "swim" };
const string terminator = ".";

Word_stream wst;

bool is_terminated_sentence();
bool is_sentence();
bool is_conjunction();
bool is_noun();
bool is_verb();
bool terminal_word(const vector<string>& v);
ostream& operator<<(ostream& os, const vector<string>& x);

int main()
{
     cout << "This program recognizes simple sentences made from these words:\n"
	  << nouns << ", " << verbs << ", " << conjunctions << ".\n"
	  << "Sentences must be terminated with a dot.\n"
	  << "Tokens must be delimited with spaces.\n"
	  << "To exit enter '" << terminator << "'.\n";

     while (cin) {
	  cout << "> " << flush;
	  if (!cin || wst.peek() == terminator)
	       break;
	  bool result = is_terminated_sentence();
	  if (result) cout << "Correct sentence\n";
	  else {
	       cout << "Incorrect sentence\n"  
		    << "Bad input: " << wst.peek() << '\n';
	       while (cin && wst.get() != terminator)
		    ;
	  }	       
     }
}

bool terminal_word(const vector<string>& v)
{
     string w = wst.get();
     bool found = find(v.begin(), v.end(), w) != v.end();
     if (!found)
	  wst.putback(w);
     return found;
}
	  

bool is_terminated_sentence()
{
     string w;
     if (!is_sentence())
	  return false;
     else if ((w=wst.get()) == terminator)
	  return true;
     else {
	  wst.putback(w);
	  return false;
     }
}

bool is_sentence()
{
     do
	  if (!is_noun() || !is_verb()) return false;
     while (is_conjunction());
     return true;
}

bool is_conjunction() { return terminal_word(conjunctions); }
bool is_noun() { return terminal_word(nouns); }
bool is_verb() { return terminal_word(verbs); }

ostream& operator<<(ostream& os, const vector<string>& x)
{
     size_t s = x.size();
     if (s > 0) {
	  for (size_t i = 0; i < s-1 ; ++i)
	       os << x[i] << ", ";
	  os << x[s-1];
     }
     return os;
}

Word_stream::Word_stream() :full {false}, buffer {""} { }
const string& Word_stream::peek()
{
     if (full)
	  return buffer;
     else {
	  cin >> buffer;
	  full = true;
	  return buffer;
     }
}

string Word_stream::get()
{
     if (full) {
	  full = false;
	  return buffer;
     } else {
	  string w;
	  cin >> w;
	  return w;
     }
}

void Word_stream::putback(string w)
{
     if (full)
	  error("putback into a full buffer");
     full = true;
     buffer = w;
}
