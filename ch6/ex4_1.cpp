#include "ex4.h"
bool Name_score::operator==(const Name_score& n) const
{
     return score == n.score && name == n.name;
}

bool Name_score::operator!=(const Name_score& n) const
{
     return !(*this == n);
}

bool Name_score::operator<=(const Name_score& n) const
{
     return name <= n.name;
}

bool Name_score::operator<(const Name_score& n) const
{
     return name < n.name;
}

ostream& operator<<(ostream& os, const Name_score& n)
{
     return os << n.name << '\t' << n.score;
}

istream& operator>>(istream& is, Name_score& n)
{
     if (!(is >> n.name))
	  return is;
     return is >> n.score;
}
